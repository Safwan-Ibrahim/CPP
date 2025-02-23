// Created on: 2025-02-21 21:31
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 8;
vector<int> G[N];
int Dep[N];

int mx, lf;

void dfs(int u, int p) {
    for (auto v : G[u]) {
        if (v != p) {
            Dep[v] = Dep[u] + 1;
            if (Dep[v] > mx) {
                mx = Dep[v];
                lf = v;
            }
            dfs(v, u);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n, m; cin >> n; 
    m = n - 1;
    while(m--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1, 0);
    mx = 0; int lf1 = lf;
    memset(Dep, 0, (n + 1) * 4);

    dfs(lf, 0);

    cout << mx << " " << lf1 << " " << lf << endl; 
    return 0;
} 