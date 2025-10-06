// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17, mod = 1e9 + 7;
vector<int> G[nn];
int n, Dept[nn], St[nn];

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

void dfs(int u, int p) {
    for (auto v : G[u]) {
        if (v != p) {
            Dept[v] = Dept[u] + 1;
            dfs(v, u);
            St[u] += St[v];
        }
    }
    St[u]++;
}

void Try() {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        St[i] = Dept[i] = 0;
    }

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int sp = -1;
    for (int i = 1; i <= n; i++) {
        if (G[i].size() > 3 || G[i].size() == 3 && i == 1) {
            cout << 0 << endl; return;
        }
        if (G[i].size() == 3 || G[i].size() == 2 && i == 1) {
            if (sp != -1) {
                cout << 0 << endl; return;
            }
            sp = i;
        }
    }

    if (sp == -1) {
        cout << power(2, n, mod) << endl; return;
    }

    Dept[1] = 1;
    dfs(1, 0);

    vector<int> V;
    for (auto v : G[sp]) {
        V.push_back(St[v]);
    }
    
    
    sort(V.begin(), V.end());
    if (V.size() > 2) V.pop_back();
    
    int mx = V.back(), mn = V.front();
    int ans;
    if (mn == mx) {
        ans = power(2, Dept[sp] + 1, mod);
    }
    else {
        ans = 1LL * power(2, Dept[sp], mod) * (power(2, mx - mn, mod) + power(2, mx - mn - 1, mod)) % mod;
    }

    cout << ans << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 