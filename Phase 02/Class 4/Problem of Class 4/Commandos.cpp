// Created on: 2025-02-22 04:18
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, m; cin >> n >> m;
    vector<int> G[n + 1];
    vector<bool>Vs(n + 1, false);
    vector<int>D1(n + 1, 0), D2(n + 1, 0);

    while(m--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int s, e; cin >> s >> e;
    
    queue<int>Q; Q.push(s);
    Vs[s] = true;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto v : G[u]) {
            if (!Vs[v]) {
                Vs[v] = true;
                Q.push(v);
                D1[v] = D1[u] + 1;
            }
        }
    }

    Vs.assign(n + 1, 0);
    Q.push(e);
    Vs[e] = true;

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto v : G[u]) {
            if (!Vs[v]) {
                Vs[v] = true;
                Q.push(v);
                D2[v] = D2[u] + 1;
            }
        }
    }

    int mx = -1;
    for (int i = 0; i < n; i++) {
        mx = max(mx, D1[i] + D2[i]);
    }

    cout << mx << endl;
    
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