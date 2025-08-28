// Created on: 2025-08-24 03:33
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
vector<int> G[nn];
int n, a, b, Have[nn], Dis[nn], P[nn];

void dfs(int u, int p) {
    P[u] = p;
    if (u == a) Have[u] = true;
    for (auto v : G[u]) {
        if (v != p) {
            Dis[v] = Dis[u] + 1;
            dfs(v, u);
            Have[u] |= Have[v];
        }
    }
}

int get_mx(int u, int p) {
    int ans = 0;
    for (auto v : G[u]) {
        if (v != p) {
            ans = max(get_mx(v, u), ans);
        }
    }
    return ans + 1;
}

void Try() {
    cin >> n >> a >> b;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(b, 0);
    int root = b; Dis[a]++;
    for (int i = 1; i <= Dis[a] / 2; i++) {
        for (auto v : G[root]) {
            if (Have[v] && v != P[root]) {
                root = v; break;
            }
        }
    } 

    cout << (n - 1) * 2 - (get_mx(root, 0) - 1) + Dis[a] / 2 << endl;

    for (int i = 1; i <= n; i++) {
        G[i].clear();
        Have[i] = 0;
        Dis[i] = 0;
        P[i] = 0;
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