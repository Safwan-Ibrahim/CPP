// Created on: 2025-08-07 23:02
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17, mod = 1e9 + 7;
int n, m; 
vector<int> G[nn];
bool Vs[nn];

int Fact[nn], IFact[nn], Dept[nn];

int power(int x, int n) {
    int ans = 1 % mod;
    while(n > 0) {
        if (n & 1) {
            ans = 1LL * ans * x % mod;
        }
        n >>= 1;
        x = 1LL * x * x % mod;
    }  
    return ans; 
}

void prec() {
    int n = nn - 5;
    Fact[0] = 1 % mod;
    for (int i = 1; i <= n; i++) {
        Fact[i] = 1LL * Fact[i - 1] * i % mod;
    }

    IFact[n] = power(Fact[n], mod - 2);
    for (int i = n - 1; i >= 0; i--) { 
        IFact[i] = 1LL * IFact[i + 1] * (i + 1) % mod;
    }
}

int nCr(int n, int r) {
    return 1LL * Fact[n] * IFact[r] % mod * IFact[n - r] % mod;
}

int nPr(int n, int r) {
    return 1LL * Fact[n] * IFact[n - r] % mod;
}

int cnt_2, comp; bool cy;
int cnt, o, e;
void dfs(int u, int p) {
    Vs[u] = true;
    cnt++;
    o += Dept[u] % 2 == 1;
    e += Dept[u] % 2 == 0;
    for (auto v : G[u]) {
        if (v != p) {
            if (Vs[v]) cy = true;
            else {
                Dept[v] = Dept[u] + 1;
                dfs(v, u);
            }
        }
    }
}

void Try() { 
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!Vs[i]) {
            cnt = 0;
            o = e = 0;
            dfs(i, 0); comp++;
            cnt_2 += cnt > 2 && min(e, o) > 1;
        }
    }

    if (cy) {
        cout << 0 << endl;
    }
    else {
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            int c = 0;
            for (auto v : G[i]) {
                if (G[v].size() == 1) c++;
            }
            if (G[i].size() - c > 2) ans *= 0;
            ans = 1LL * ans * Fact[c] % mod;
        }
        ans = 1LL * ans * Fact[comp] % mod;
        ans = 1LL * ans * power(2, cnt_2) % mod;
        ans = 1LL * ans * 2 % mod;
        cout << ans << endl;
    }

    for (int i = 1; i <= n; i++) {
        G[i].clear();
        Vs[i] = 0;
        Dept[i] = 0;
    }
    cnt_2 = 0, comp = 0;
    cy = 0, cnt = 0;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t; prec();
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 