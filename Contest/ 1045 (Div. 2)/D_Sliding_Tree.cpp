// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, Dep[nn], P[nn];
vector<int> G[nn];

void dfs(int u, int p) {
    P[u] = p;
    for (auto v : G[u]) {
        if (v != p) {
            Dep[v] = Dep[u] + 1;
            dfs(v, u);
        }
    }
}

void Try() {
    cin >> n;
    
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    bool al = true;
    for (int i = 1; i <= n; i++) {
        if (G[i].size() > 2) {
            al = false;
        }
    }

    int rt = 0;
    if (al) {
        cout << -1 << endl;
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (G[i].size() == 1) {
                rt = i;
                dfs(i, 0); break;
            }
        }

        int mn = 1e9, nd;
        for (int i = 1; i <= n; i++) {
            cerr << i << " " << P[i] << endl;
            if (rt == i) continue;
            if (G[i].size() == 1) {
                if (mn > Dep[i]) {
                    mn = Dep[i];
                    nd = i;
                }
            }
        }
        cerr  << rt << endl;
        cout << nd << " " << P[nd] << " " << P[P[nd]] << endl;
    }

    for (int i = 1; i <= n; i++) {
        G[i].clear();
        Dep[i] = 0;
        P[i] = 0;
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