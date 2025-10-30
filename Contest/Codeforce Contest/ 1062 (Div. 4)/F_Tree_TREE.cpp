// Created on: 2025-10-30 07:36
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, k, P[nn], S[nn]; 
vector<int> G[nn];

void dfs(int u, int p) {
    P[u] = p;
    S[u] = 1;
    for (auto v : G[u]) {
        if (v != p) {
            dfs(v, u);
            S[u] += S[v];
        }
    }
}

void Try() {
    cin >> n >> k;

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    dfs(1, 0);

    ll ans = n;
    for (int u = 1; u <= n; u++) {
        for (auto v : G[u]) {
            if (v == P[u]) {
                ans += (n - S[u]) * (S[u] >= k);
            }
            else {
                ans += S[v] * (n - S[v] >= k);
            }
        }
    }

    cout << ans << endl;

    for (int i = 1; i <= n; i++) {
        G[i].clear(); 
        P[i] = S[i] = 0;
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