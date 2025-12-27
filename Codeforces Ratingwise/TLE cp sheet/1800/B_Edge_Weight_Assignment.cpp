// Created on: 2025-11-24 15:19
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int n; vector<int> G[nn];

pair<bool, bool> is_odd(int u, int p) {
    pair<bool, bool> s = {0, 0};
    for (auto v : G[u]) {
        if (v != p) {
            auto cp = is_odd(v, u);
            s.first |= cp.second;
            s.second |= cp.first;
        }
    }

    if (G[u].size() == 1) s = {0, 1};
    return s;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    int mn = 1, mx = n - 1, root = 1;
    for (int i = 1; i <= n; i++) {
        if (G[i].size() != 1) root = i;

        int cnt = 0;
        for (auto v : G[i]) {
            cnt += G[v].size() == 1;
        }

        mx -= max(0, cnt - 1);
    }

    auto o = is_odd(root, 0);
    if (o.second && o.first) mn = 3;

    cout << mn << " " << mx << endl;

    return 0;
} 