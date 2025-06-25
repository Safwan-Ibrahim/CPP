// Created on: 2025-06-23 14:43
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, m, A[nn];
vector<pair<int, int>> G[nn];

bool bfs(int x) {
    vector<ll>Mx_batt(n + 1, -1e9);
    Mx_batt[1] = A[1];
    for (int u = 1; u <= n; u++) {
        for (auto [v, w] : G[u]) {
            if (w <= x && w <= Mx_batt[u] && A[v] + Mx_batt[u] > Mx_batt[v]) {
                Mx_batt[v] = Mx_batt[u] + A[v];
            }
        }
    }
    return Mx_batt[n] != -1e9;
}

void Try() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    int mx = -1;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        G[u].push_back({v, w});
        mx = max(mx, w);
    }

    int ans = -1, lo = 1, hi = mx;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (bfs(mid)) {
            ans = mid; hi = mid - 1;
        }
        else lo = mid + 1;
    }

    cout << ans << endl;
    
    for (int i = 1; i <= n; i++) {
        G[i].clear();
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