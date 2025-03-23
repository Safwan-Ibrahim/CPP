// Created on: 2025-03-22 22:50
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 8, M = 1e9 + 7;
vector<int>G[N];
int Ans[2][N];

void dfs(int u, int p) {
    Ans[0][u] = 1;
    Ans[1][u] = 1;
    for (auto v : G[u]) {
        if (v != p) {
            dfs(v, u);
            Ans[0][u] = 1LL * Ans[0][u] * (Ans[0][v] + Ans[1][v]) % M;
            Ans[1][u] = 1LL * Ans[1][u] * Ans[0][v] % M;
        }
    }
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
    cout << (Ans[0][1] + Ans[1][1]) % M << endl;

    return 0;
} 