// Created on: 2025-02-06 03:28
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 105;
vector<int> G[N]; // better graph
bool Vs[N], ok;
int C[N];

void dfs(int u) {
    Vs[u] = true;
    for (auto x : G[u]) {
        if (!Vs[x]) {
            C[x] = C[u] ^ 1;
            dfs(x);
        }
        else {
            if (C[x] == C[u]) { 
                ok = false;
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n, m; cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    ok = true;
    dfs(1); // if graph is connected then one dfs else loop chaliye dfs 
    // for (int i = 1; i <= n; i++) {
    //     if (!Vs[i]) {
    //         dfs(i);
    //     }
    // }


    return 0;
} 