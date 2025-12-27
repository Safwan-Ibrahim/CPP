// Created on: 2025-12-10 05:02
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17, ec = nn - 3;
int n, D[nn], U[nn], B1[nn], B2[nn];
vector<int> G[nn];

void dfs(int u, int p) {
    
    D[u] = 0;
    B1[u] = B2[u] = ec;
    int mx = 0, smx = 0;

    for (auto v : G[u]) {
        if (v != p) {
            dfs(v, u);
            D[u] = max(D[u], 1 + D[v]);
            if (D[v] >= mx) {
                smx = mx;
                mx = D[v];
                B2[u] = B1[u];
                B1[u] = v;
            }
            else if (D[v] > smx) {
                smx = D[v];
                B2[u] = v;
            }
        }
    }
}

void dfs2(int u, int p) {

    if (p != 0) {
        U[u] = 1 + U[p];
        int v = (B1[p] == u ? B2[p] : B1[p]);
        U[u] = max(U[u], 2 + D[v]);
    }

    for (auto v : G[u]) {
        if (v != p) {
            dfs2(v, u);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    D[ec] = -2;
    dfs(1, 0);
    dfs2(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << max(U[i], D[i]) << " ";
    }
    cout << endl;

    return 0;
} 