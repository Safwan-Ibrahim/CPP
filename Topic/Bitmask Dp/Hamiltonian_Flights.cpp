// Created on: 2025-12-12 05:33
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 23, mod = 1e9 + 7;
vector<int> G[nn];
int n, m, Ans[nn][1 << 20];

int way(int u, int track) {
    if (u == n - 1) return __builtin_popcount(track) == n;
    if (~Ans[u][track]) return Ans[u][track];

    int ans = 0;
    for (auto v : G[u]) {
        if (!((track >> v) & 1)) {
            ans += way(v, track | (1 << v));
            ans %= mod;
        }
    }

    return Ans[u][track] = ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> m; 

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
    }

    memset(Ans, -1, sizeof Ans);

    cout << way(0, 1) << endl; 
    
    return 0;
} 