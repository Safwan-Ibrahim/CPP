

// Created on: 2025-03-14 03:03
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 8;
vector<pair<int, int>>G[N];
ll D[N], Ans[N], mx;
int fn;

void dfs(int u, int p) {
    for (auto [v, cost] : G[u]) {
        if (v != p) {
            D[v] = D[u] + cost;
            if (D[v] > mx) {
                mx = D[v];
                fn = v;
            }
            dfs(v, u);
        }
    }
}



void Try() {
    int n; cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v, cost; cin >> u >> v >> cost;
        u++, v++;
        G[u].push_back({v, cost});
        G[v].push_back({u, cost});
    }

    D[1] = mx = 0;
    dfs(1, 0);
    
    D[fn] = mx = 0; 
    dfs(fn, 0);
    for (int i = 1; i <= n; i++) {
        Ans[i] = D[i];
    }

    D[fn] = mx = 0;
    dfs(fn, 0);

    for (int i = 1; i <= n; i++) {
        cout << max(Ans[i], D[i]) << endl;
    }
    
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        Ans[i] = 0;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";
        Try();
    }
    return 0;
} 