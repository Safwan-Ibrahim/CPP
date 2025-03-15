// Created on: 2025-03-13 03:54
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 208;
vector<int>G[N]; // remember to clear
int Col[N]; // remember to clear
bool ok, Vs[N]; // remember to clear

void dfs(int u, int p) {
    Col[u] = Col[p] ^ 1;
    Vs[u] = true; 
    for (auto v : G[u]) {
        if (!Vs[v]) {
            dfs(v, u);
        }
        else {
            if (Col[u] == Col[v]) {
                ok = false;
            }
        }
    }
}

void Try(int n) {
    int m; cin >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        u++, v++;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    ok = true;
    dfs(1, 0);
    if (!ok) {
        cout << "NOT ";
    }
    cout << "BICOLORABLE.\n";

    for (int i = 1; i <= n; i++) {
        G[i].clear();
        Vs[i] = false;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while(cin >> n && n != 0) {
        Try(n);
    }
    
    return 0;
} 