// Created on: 2025-07-16 01:26
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, Par[nn];
vector<int> G[nn];
vector<pair<int, int>> Ans, Ans2; 

void dfs(int u, int p, bool f) {
    Par[u] = p;
    bool call = false;
    int cnt = 0;
    for (auto v : G[u]) {
        if (p == 0 && cnt == 1) f ^= 1;
        if (v != p) {
            if (f) Ans.push_back({u, v});
            else Ans.push_back({v, u});
            dfs(v, u, f ^ 1);
            call = true;
        }
        cnt++;
    }
}

void Try() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    bool yes = false;
    for (int i = 1; i <= n; i++) {
        if (G[i].size() == 2) {
            dfs(i, 0, 0);
            yes = true;
            break;
        }
    }

    if (yes && n != 2) {
        cout << "YES\n";
        for (auto [x, y] : Ans) {
            cout << x << " " << y << endl;;
        }
    }
    else cout << "NO\n";
    
    Ans.clear();
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        Par[i] = 0;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 