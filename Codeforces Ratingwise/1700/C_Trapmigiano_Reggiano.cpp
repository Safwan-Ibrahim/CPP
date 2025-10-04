// Created on: 2025-06-26 20:14
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
vector<int> G[nn];
set<int> Mt[nn]; // my tree
int n, st, en, P[nn];
vector<int>Ans;

void dfs1(int u, int p) {
    for (auto v : G[u]) {
        if (v != p) {
            P[v] = u;
            Mt[u].insert(v);
            dfs1(v, u);
        }
    }
}

void dfs2(int u) {
    for (auto v : Mt[u]) {
        dfs2(v);
    }
    Ans.push_back(u);
}

void Try() {
    cin >> n >> st >> en;

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs1(en, 0);

    while (st != 0) {
        dfs2(st);
        Mt[P[st]].erase(st);
        st = P[st];
    }

    for (auto x : Ans) {
        cout << x << " ";
    }
    cout << endl;
    
    for (int i = 1; i <= n; i++) {
        G[i].clear(); Mt[i].clear();
        P[i] = 0;
    }
    Ans.clear();
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 