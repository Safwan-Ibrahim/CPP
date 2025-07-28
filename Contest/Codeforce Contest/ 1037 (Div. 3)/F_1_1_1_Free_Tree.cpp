// Created on: 2025-07-17 22:37
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll ans;
const int nn = 2e5 + 17;
int n, A[nn], Par[nn], Pv[nn];
vector<pair<int, int>> G[nn];
vector<map<int, ll>>Mp(nn);

void dfs(int u, int p, int pv) {
    Par[u] = p;
    Pv[u] = pv;
    for (auto [v, w] : G[u]) {
        if (v != p) {
            if (A[v] != A[u]) {
                ans += w;
            }
            Mp[u][A[v]] += w;
            dfs(v, u, w);
        }
    }
}

void Try() {
    int q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    dfs(1, 0, 0); int u, col;
    for (int _ = 1; _ <= q; _++ ) {
        cin >> u >> col;
        if (A[u] == col) {
            cout << ans << endl; continue;
        }
        ans -= Mp[u][col];
        ans += Mp[u][A[u]];
        int p = Par[u];
        if (p == 0) {
            cout << ans << endl;
            A[u] = col; continue;
        }
        Mp[p][A[u]] -= Pv[u];
        Mp[p][col] += Pv[u];
        if (A[p] == A[u]) {
            ans += Pv[u];
        }
        else if (A[p] == col) {
            ans -= Pv[u];
        }
        A[u] = col;
        cout << ans << endl;
    }
    
    ans = 0;
    for (int i = 1; i <= n; i++) {
        Mp[i].clear();
        G[i].clear();
        Par[i] = Pv[i] = 0;
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