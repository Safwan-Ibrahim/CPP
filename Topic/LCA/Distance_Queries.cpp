// Created on: 2025-12-07 01:21
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17, mm = 22;
int n, q, Dept[nn], Up[nn][mm];
vector<int> G[nn];

void dfs(int u, int p) {
    for (int v : G[u]) {
        if (v != p) {
            Up[v][0] = u;

            for (int i = 1; i < mm; i++) {
                Up[v][i] = Up[Up[v][i - 1]][i - 1];
            }

            Dept[v] = Dept[u] + 1;
            dfs(v, u);
        }
    }
}

int lca(int a, int b) {
    if (Dept[b] > Dept[a]) {
        swap(a, b);
    }

    int k = Dept[a] - Dept[b];

    for (int i = mm - 1; i >= 0; i--) {
        if ((k >> i) & 1) {
            a = Up[a][i];
        }
    }

    if (a == b) return a;

    for (int i = mm - 1; i >= 0; i--) {
        if (Up[a][i] != Up[b][i]) {
            a = Up[a][i], b = Up[b][i];
        }
    }

    return Up[a][0];
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n >> q;

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1, 0);

    while (q--) {
        int u, v; cin >> u >> v;
        int lc = lca(u, v);
        cout << Dept[v] - Dept[lc] + Dept[u] - Dept[lc] << endl;
    }

    return 0;
} 