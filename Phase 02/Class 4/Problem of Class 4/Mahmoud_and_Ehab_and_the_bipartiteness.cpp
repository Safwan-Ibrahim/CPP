// Created on: 2025-03-13 15:50
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 8;
vector<int>G[N];
bool Vs[N];
int Col[N];

void dfs(int u, int p) {
    Col[u] = Col[p] ^ 1;
    Vs[u] = true;
    for (auto v : G[u]) {
        if (!Vs[v]) {
            dfs(v, u);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1, 0);
    
    int cnt0 = 0;
    for (int i = 1; i <= n; i++) {
        cnt0 += Col[i] == 0;
    }   
    
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (Col[i] == 1) {
            int con = G[i].size();
            ans += cnt0 - con;
        }
    }

    cout << ans << endl;

    
    return 0;
} 