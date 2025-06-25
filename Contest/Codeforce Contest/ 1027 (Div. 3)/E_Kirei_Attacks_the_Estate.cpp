// Created on: 2025-05-26 22:02
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 18;
vector<int> G[nn];
ll n, A[nn];
ll Mn[nn], Mx[nn];

void dfs(int u, int p) {
    for (auto v : G[u]) {
        if (v != p) {
            Mn[v] = min(Mn[v], A[v] - Mx[u]);
            Mx[v] = max(Mx[v], A[v] - Mn[u]);
            dfs(v, u);
        }
    }
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    Mx[1] = A[1];
    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << Mx[i] << " ";
        G[i].clear();
        Mn[i] = Mx[i] = 0;
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 