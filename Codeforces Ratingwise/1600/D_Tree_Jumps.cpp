// Created on: 2025-06-10 06:01
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 3e5 + 17, mod = 998244353;
vector<int> G[nn];
int n, mx, Dept[nn], Ans[nn];

void dfs(int u) {
    mx = max(mx, Dept[u]);
    for (auto v : G[u]) {
        Dept[v] = Dept[u] + 1;
        dfs(v);
    }
}

void Try() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int u; cin >> u;
        G[u].push_back(i);
    }

    dfs(1);
    vector<vector<int>>V(mx + 1);
    for (int i = 1; i <= n; i++) {
        V[Dept[i]].push_back(i);
    }
    
    int sum = 0, new_sum = 0;
    for (int i = mx; i >= 1; i--) {
        for (auto u : V[i]) {
            Ans[u] = 1 + sum; Ans[u] %= mod;
            for (auto v : G[u]) {
                Ans[u] -= Ans[v];
                Ans[u] = (Ans[u] + mod) % mod;
            }
            new_sum += Ans[u]; new_sum %= mod;
        }
        sum = new_sum;
        new_sum = 0;
    }

    Ans[1] = 1;
    for (auto v : G[1]) {
        Ans[1] = (Ans[1] + Ans[v]) % mod;
    }
    
    cout << Ans[1] << endl;
    
    mx = 0;
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        Dept[i] = Ans[i] = 0;
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