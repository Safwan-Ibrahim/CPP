// Created on: 2025-03-09 23:13
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

vector<int> G[105];
int Dep[105];

void dfs(int u, int p) {
    Dep[u] = Dep[p] + 1;
    for (auto v : G[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << Dep[i] << ' ';
    }
    
    return 0;
}