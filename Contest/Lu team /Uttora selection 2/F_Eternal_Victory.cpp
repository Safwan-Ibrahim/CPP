// Created on: 2025-06-02 15:45
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 18;
vector<pair<int, int>> G[nn];
int n;
ll Cost[nn], mx, ans;

void dfs(int u, int p) {
    mx = max(mx, Cost[u]);
    for (auto [v, cost] : G[u]) {
        if (v != p) {
            Cost[v] = Cost[u] + cost;
            dfs(v, u);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, cost; cin >> u >> v >> cost;
        G[u].push_back({v, cost});
        G[v].push_back({u, cost});
        ans += 2 * cost;
    }
    
    dfs(1, 0);
    cout << ans - mx << endl;

    return 0;
} 