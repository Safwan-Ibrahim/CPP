// Created on: 2025-05-28 19:39
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 18;
int n, Mx[nn], Mn[nn];
vector<int> G[nn];
ll Ans[2][nn];

void dfs(int u, int p) {
    Ans[0][u] = Ans[1][u] = 0;
    for (auto v : G[u]) {
        if (v != p) {
            dfs(v, u);
            Ans[0][u] += max(abs(Mn[u] - Mn[v]) + Ans[0][v], abs(Mn[u] - Mx[v]) + Ans[1][v]);
            Ans[1][u] += max(abs(Mx[u] - Mn[v]) + Ans[0][v], abs(Mx[u] - Mx[v]) + Ans[1][v]);
        }
    }
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> Mn[i] >> Mx[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1, 0);
    cout << max(Ans[0][1], Ans[1][1]) << endl;

    for (int i = 1; i <= n; i++) {
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