// Created on: 2025-07-03 12:46
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
vector<pair<int, int>> G[nn];
int n, a, b, Cost[nn];
set<int>St;

void dfs1(int u, int p) {
    for (auto [v, w] : G[u]) {
        if (v != p) {
            Cost[v] = Cost[u] ^ w;
            dfs1(v, u);
        }
    }
}

void dfs2(int u, int p, int cost) {
    St.insert(cost);
    for (auto [v, w] : G[u]) {
        if (v != p && v != b) {
            dfs2(v, u, cost ^ w);
        }
    }
}

void Try() {
    cin >> n >> a >> b;
    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    dfs1(b, 0);
    dfs2(a, 0, 0);

    bool yes = false;
    for (int i = 1; i <= n; i++) {
        if (i == b) continue;
        if (St.count(Cost[i])) yes = true;
    }

    cout << (yes ? "YES\n" : "NO\n");
    
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        Cost[i] = 0;
    }
    St.clear();
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 