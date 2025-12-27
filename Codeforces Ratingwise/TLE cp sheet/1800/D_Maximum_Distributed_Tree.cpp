// Created on: 2025-11-20 14:35
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17, mod = 1e9 + 7;
vector<int> G[nn];
int n, m, Cnt[nn];

void dfs(int u, int p) {
    Cnt[u] = 1;
    for (auto v : G[u]) {
        if (v != p) {
            dfs(v, u);
            Cnt[u] += Cnt[v];
        } 
    }
}

void Try() {
    cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    dfs(1, 0);

    cin >> m;

    vector<int> V(m);
    for (int i = 0; i < m; i++) {
        cin >> V[i];
    }

    vector<ll> C;
    for (int i = 2; i <= n; i++) {
        C.push_back(1LL * (n - Cnt[i]) * Cnt[i]);
    }

    sort(C.rbegin(), C.rend());
    sort(V.rbegin(), V.rend());

    int ans = 0;

    for (int i = 0; i < C.size(); i++) {
        C[i] %= mod;
    }

    for (int i = 1; i <= max(0, n - 1 - m); i++) {
        ans += 1LL * C.back(); ans %= mod;
        C.pop_back();
    }

    for (int i = C.size() - 1; i > 0; i--) {
        ans += 1LL * V.back() * C[i] % mod;
        ans %= mod;
        V.pop_back();
    }

    int cont = 1;
    for (auto x : V) {
        cont = 1LL * cont * x % mod;
    }

    ans += 1LL * C[0] * cont % mod;
    ans %= mod;

    cout << ans << endl;

    for (int i = 1; i <= n; i++) {
        G[i].clear();
        Cnt[i] = 0;
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