// Created on: 2025-05-02 20:19
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8;
vector<int>G[nn];
int n, m;

bool ok(int l, int r) {
    auto up = upper_bound(G[r].begin(), G[r].end(), r);
    auto lo = lower_bound(G[r].begin(), G[r].end(), l);
    return up - lo == 0;
}

void Try() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(G[i].begin(), G[i].end());
    }

    int r = 1;
    ll ans = 0;
    for (int l = 1; l <= n; l++) {
        while(r + 1 <= n && ok(l, r + 1)) {
            r++;
        }
        ans += r - l + 1;
    }

    for (int i = 1; i <= n; i++) {
        G[i].clear();
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