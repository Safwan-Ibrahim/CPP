// Created on: 2025-03-16 07:36
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e3 + 8;
vector<int> G1[N], G2[N];
vector<bool>Vs;
vector<pair<int, int>>Ans;
int color, n, Col1[N], Col2[N];

void dfs1(int u) {
    Vs[u] = true;
    Col1[u] = color;
    for (auto v : G1[u]) {
        if (!Vs[v]) {
            dfs1(v);
        }
    }
}

void dfs2(int u) {
    Vs[u] = true;
    Col2[u] = color;
    for (auto v : G2[u]) {
        if (!Vs[v]) {
            dfs2(v);
        }
    }
}

void same(int use1, int change1, int use2, int change2) {
    for (int i = 1; i <= n; i++) {
        if (Col1[i] == change1) {
            Col1[i] = use1;
        }
        if (Col2[i] == change2) {
            Col2[i] = use2;
        }
    }
}

void solve() {
    Vs.assign(n + 1, false);
    color = 0;
    for (int i = 1; i <= n; i++) {
        if (!Vs[i]) {
            color++;
            dfs1(i);
        }
    }
    
    Vs.assign(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!Vs[i]) {
            ++color;
            dfs2(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (Col1[i] != Col1[j] && Col2[i] != Col2[j]) {
                Ans.push_back({i, j});
                same(Col1[i], Col1[j], Col2[i], Col2[j]);
            }
        }
    }

    return;
}   

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int m1, m2; cin >> n >> m1 >> m2;
    while(m1--) {
        int u, v; cin >> u >> v;
        G1[u].push_back(v);
        G1[v].push_back(u);
    }
    while(m2--) {
        int u, v; cin >> u >> v;
        G2[u].push_back(v);
        G2[v].push_back(u);
    }
    
    solve();

    cout << Ans.size() << endl;
    for (auto [x, y] : Ans) {
        cout << x << " " << y << endl;
    }
    
    return 0;
} 