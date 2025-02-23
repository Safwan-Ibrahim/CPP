// Created on: 2025-02-22 02:23
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 105;
vector<pair<int, int>> G[N];
bool Vs[N];
int last, cost;

void dfs(int u) {
    Vs[u] = true;
    bool call = false;
    for (auto [v, x] : G[u]) {
        if (!Vs[v]) {
            call = true;
            cost += x;
            dfs(v);
        }
    }
    if (!call) {
        for (auto [v, x] : G[u]) {
            if (v == 1) {
                cost += x; return;
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n; cin >> n;
    int total = 0;
    for (int i = 1; i <= n; i++) {
        int u, v, x; cin >> u >> v >> x;
        G[u].push_back({v, 0});
        G[v].push_back({u, x});
        total += x;
    }

    dfs(1);

    cout << min(cost, total - cost) << endl;

    return 0;
} 