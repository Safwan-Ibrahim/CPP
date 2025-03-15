// Created on: 2025-03-13 06:23
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e3 + 8;
vector<int>G[N]; // rem to clear
bool ok, Vs[N];
int Col[N];

void dfs(int u, int p = 0) {
    Vs[u] = true;
    Col[u] = Col[p] ^ 1;
    for (auto v : G[u]) {
        if (!Vs[v]) {
            dfs(v, u);
        }
        else if (Col[v] == Col[u]) {
            ok = false;
        }
    }
}

void Try() {
    int n, m; cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    ok = true;
    for (int i = 1; i <= n; i++) {
        if (!Vs[i]) {
            dfs(i);
        }
    }

    if (!ok) {
        cout << "Suspicious bugs found!\n";
    }
    else {
        cout << "No suspicious bugs found!\n";
    }

    for (int i = 1; i <= n; i++) {
        Vs[i] = false;
        G[i].clear();
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Scenario #" << i << ":\n";
        Try();
    }
    return 0;
} 