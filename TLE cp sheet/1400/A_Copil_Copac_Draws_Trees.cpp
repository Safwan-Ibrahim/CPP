// Created on: 2025-05-02 14:32
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
vector<pair<int, int>> G[nn];
int n, T[nn];

void dfs(int u, int p, int id_u) {
    for (auto [v, id_v] : G[u]) {
        if (v != p) {
            T[v] = T[u] + (id_v < id_u);
            dfs(v, u, id_v);
        }
    }
}

void Try() {
    cin >> n;
    int go = 0;
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
        if (go == 0 && min(u, v) == 1) {
            go = i;
        } 
    }

    T[1] = 1;
    dfs(1, 0, go);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, T[i]);
        T[i] = 0;
        G[i].clear();
    }

    cout << mx << endl;


}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 