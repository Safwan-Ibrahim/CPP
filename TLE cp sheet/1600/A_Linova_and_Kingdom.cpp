// Created on: 2025-05-31 17:28
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
vector<int> G[nn];
int Subtree[nn], Dept[nn];

void dfs(int u, int p) {
    Subtree[u] = 1;
    Dept[u] = 1 + Dept[p];
    for (auto v : G[u]) {
        if (v != p) {
            dfs(v, u);
            Subtree[u] += Subtree[v];
        }
    }
}

priority_queue<pair<ll, int>>Pq;

void dfs_push(int u, int p) {
    ll self = 1LL * (Subtree[u] - 1) * Dept[u];
    Pq.push({self - (1LL * Subtree[u] * Dept[p]), u});
    for (auto v : G[u]) {
        if (v != p) dfs_push(v, u);
    }
}

bool Tourism[nn];
ll ans; 
int Happines[nn];

void dfs_calc(int u, int p) {
    Happines[u] = Tourism[u] + Happines[p];
    if (!Tourism[u]) ans += Happines[u];
    for (auto v : G[u]) {
        if (v != p) dfs_calc(v, u);
    }
}


int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, step; cin >> n >> step;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    dfs(1, 0);
    step = n - step;
    dfs_push(1, 0);
    for (int i = 1; i <= step; i++) {
        auto [cnt, u] = Pq.top();
        Pq.pop();
        Tourism[u] = true;
    }
    
    dfs_calc(1, 0);
    cout << ans << endl;
    
    return 0;
} 