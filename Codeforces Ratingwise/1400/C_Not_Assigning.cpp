// Created on: 2025-03-16 01:57
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 8;
vector<pair<int, int>> G[N];
int E[N];
bool two;

void dfs(int u, int p) {
    for (auto [v, e] : G[u]) {
        if (v != p) {
            E[e] = (two ? 2 : 5);
            two ^= 1;
            dfs(v, u);
        }
    }
}

void Try() {
    int n; cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }

    bool can = true;
    int st;
    for (int i = 1; i <= n; i++) {
        if (G[i].size() > 2) {
            can = false;
        }
        else if (G[i].size() == 1) {
            st = i;
        }
    }

    if (can) {
        two = true;
        dfs(st, 0);
        for (int i = 1; i <= n - 1; i++) {
            cout << E[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << -1 << endl;
    }

    
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