// Created on: 2025-03-22 22:26
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 8;
vector<int>G[N];
int Ans[N];

int dfs(int u) {
    if (Ans[u] != -1) {
        return Ans[u];
    }
    int ans = 0;
    for (auto v : G[u]) {
        ans = max(ans, 1 + dfs(v));
    }
    return Ans[u] = ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n, m; cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
    }
    
    memset(Ans, -1, sizeof Ans);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dfs(i));
    }
    cout << ans << endl;
    return 0;
} 