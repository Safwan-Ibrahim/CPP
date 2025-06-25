// Created on: 2025-06-02 13:16
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int nn = 3e5 + 108;
vector<pair<int, int>> G[nn];
int n, Gas[nn];
int mx = 0;

void dfs(int u, int p, int node_count, int gas) {
    gas += Gas[u];
    mx = max(mx, gas);
    if (node_count == 3) return;
    for (auto [v, l] : G[u]) {
        if (v != p) {
            if (l <= gas) dfs(v, u, node_count + 1, gas - l);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> Gas[i];
    }
    
    for (int i = 1; i < n; i++) {
        int u, v, l; cin >> u >> v >> l;
        G[u].push_back({v, l});
        G[v].push_back({u, l});
    }

    for (int i = 1; i <= n; i++) {
        dfs(i, 0, 1, 0);
    }

    cout << mx << endl;

    return 0;
} 