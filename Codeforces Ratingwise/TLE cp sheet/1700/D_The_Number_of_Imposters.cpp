// Created on: 2025-07-15 06:06
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
vector<pair<int, int>> G[nn];
int n, m, Col[nn], Cnt[2]; 
bool p;

void dfs (int u, int col) {
    Cnt[col]++;
    Col[u] = col;
    for (auto [v, w] : G[u]) {
        if (Col[v] == -1) {
            dfs(v, col ^ w);
        }
        else if (Col[v] != col ^ w) {
            p = false;
        }
    }
}

void Try() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        string s; cin >> s;
        if (s.front() == 'c') {
            G[u].push_back({v, 0});
            G[v].push_back({u, 0});
        }
        else {
            G[u].push_back({v, 1});
            G[v].push_back({u, 1});
        }
    }

    for (int i = 1; i <= n; i++) {
        Col[i] = -1;
    }

    p = true;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (Col[i] == -1) {
            Cnt[0] = Cnt[1] = 0;
            dfs(i, 0);
            ans += max(Cnt[0], Cnt[1]);
        }
    }

    cout << (p ? ans : -1) << endl;

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