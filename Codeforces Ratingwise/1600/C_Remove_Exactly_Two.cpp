// Created on: 2025-06-10 20:33
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 18;
set<int> G[nn];
int n;

void Try() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
    }

    multiset<int>Ms; Ms.insert(0);

    for (int i = 1; i <= n; i++) {
        Ms.insert(G[i].size() + 1);
    }

    int mx = 0;
    multiset<int>Tmp;
    for (int i = 1; i <= n; i++) {
        int current = G[i].size() + 1;
        Ms.erase(Ms.find(current));
        for (auto v : G[i]) {
            Tmp.insert(G[v].size());
            Ms.erase(Ms.find(G[v].size() + 1));
        }
        mx = max(mx, current + max(*Tmp.rbegin(), *Ms.rbegin()));
        Ms.insert(current);
        for (auto v : Tmp) {
            Ms.insert(v + 1);
        }
        Tmp.clear();
    }

    cout << mx - 3 << endl;

    for (int i = 1; i <= n; i++) {
        G[i].clear();
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