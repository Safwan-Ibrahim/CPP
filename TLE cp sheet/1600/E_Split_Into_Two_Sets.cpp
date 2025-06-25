// Created on: 2025-05-24 17:37
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
vector<int> G[nn];
int n, Col[nn]; 
bool yes, Vs[nn];

void dfs(int u, int p, int col) {
    Vs[u] = true;
    int cnt = 0;
    Col[u] = col;
    for (auto v : G[u]) {
        if (v != p) {
            if (Vs[v]) yes &= Col[v] != Col[u];
            else dfs(v, u, col ^ 1);
        }   
        cnt++;
    }
    yes &= cnt <= 2;
}

void Try() {
    cin >> n;
    yes = true;
    for (int i = 1; i <= n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        if (v != u) G[v].push_back(u);
        else yes = false;
    }
    
    for (int u = 1; u <= n; u++) {
        if (!Vs[u]) {
            dfs(u, 0, 1);
        }
    }

    cout << (yes ? "YES\n" : "NO\n");

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