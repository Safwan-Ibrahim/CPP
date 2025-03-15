// Author: Safwan_Ibrahim
// Created on: 2025-03-14 21:32

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 3e4 + 8;
vector<pair<int, int>> G[N]; // reset it now
int Cost[N], mx, st; // reset it now

void dfs(int u, int p) {
    for (auto [v, cost] : G[u]) {
        if (v != p) {
            Cost[v] = Cost[u] + cost;
            if (Cost[v] > mx) {
                mx = Cost[v];
                st = v;
            }
            dfs(v, u);
        }
    }
}

void Try() {
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, cost; cin >> u >> v >> cost;
        u++, v++;   
        G[u].push_back({v, cost});
        G[v].push_back({u, cost});
    }

    
    Cost[1] = mx = 0;
    dfs(1, 0);

    Cost[st] = 0; mx = 0;
    dfs(st, 0);

    cout << mx << endl;

    // reseting value
    for (int i = 1; i <= n; i++) {
        G[i].clear();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        Try();
    }
    return 0;
} 