// Created on: 2025-03-22 22:50
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 8;
vector<int>G[N];
int Sz[N];

void dfs(int u, int p) {
    int cnt = 1;
    for (auto v : G[u]) {
        if (v != p) {
            dfs(v, u);
        }
        cnt += Sz[v];  
    }
    Sz[u] = cnt;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << Sz[i] << " ";
    }
    cout << endl;
    
    return 0;
} 