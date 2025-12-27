// Created on: 2025-05-14 23:11
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8, mod = 1e9 + 7;
vector<int> G[nn];

int power(int x, int n, int m) {
    int ans = 1 % m;
    while(n > 0) {
        if (n & 1) {
            ans = 1LL * ans * x % m;
        }
        n >>= 1;
        x = 1LL * x * x % m;
    }
    return ans;
}

bool Vs[nn];
int comp;

void dfs(int u) {
    comp++;
    Vs[u] = true;
    for (auto v : G[u]) {
        if (!Vs[v]) dfs(v);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v, x; cin >> u >> v >> x;
        if (x == 0) {
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }

    int ans = power(n, k, mod);
    for (int i = 1; i <= n; i++) {
        if (!Vs[i]) {
            dfs(i);
            ans = (ans - power(comp, k, mod) + mod) % mod;
            comp = 0;
        }
    }
    
    cout << ans << endl;
    
    return 0;
} 