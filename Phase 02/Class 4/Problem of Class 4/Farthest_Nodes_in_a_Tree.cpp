// Created on: 2025-03-14 03:03
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 3e4 + 8;
vector<pair<int, int>>G[N];
int Mx[N], ans;

void dfs(int u, int p) {
    int mx = 0, smx = 0;
    for (auto [v, cost] : G[u]) {
        if (v != p) {
            dfs(v, u);
            if (Mx[v] + cost >= mx) {
                smx = mx;
                mx = Mx[v] + cost;
            }
            else {
                smx = max(smx, Mx[v] + cost);
            }
        }
    }
    Mx[u] = mx;
    ans = max(smx + mx, ans);
}

void Try() {
    int n; cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v, cost; cin >> u >> v >> cost;
        u++, v++;
        G[u].push_back({v, cost});
        G[v].push_back({u, cost});
    }

    ans = 0;
    dfs(1, 0);
    cout << ans << endl;

    // reseting value
    for (int i = 1; i <= n; i++) {
        Mx[i] = 0;
        G[i].clear();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        Try();
    }
    return 0;
} 