// Created on: 2025-05-21 14:43
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
bool Vs[nn], cy;
set<int> G[nn];

void dfs(int u, int p) {
    Vs[u] = true;
    for (auto v : G[u]) {
        if (v != p) {
            if (Vs[v]) cy = true;
            else dfs(v, u);
        }
    }
}

void Try() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int u = i, v; cin >> v;
        G[u].insert(v);
        G[v].insert(u);
    }

    int cy_cnt = 0, comp = 0;
    for (int u = 1; u <= n; u++) {
        if (!Vs[u]) {
            cy = false;
            dfs(u, 0); comp++;
            if (cy) cy_cnt++;
        }
    }

    cout << cy_cnt + (comp > cy_cnt) << " " << comp << endl;

    for (int i = 1; i <= n; i++) {
        Vs[i] = false;
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