// Created on: 2025-05-18 19:34
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8;
vector<int> G[nn];
int Num[nn], ans;

void dfs(int u, int p) {
    Num[u] = 1;
    for (auto v : G[u]) {
        if (v != p) {
            dfs(v, u);
            Num[u] += Num[v];
        }
    }
}

void dfs2(int u, int p) {
    for (auto v : G[u]) {
        if (v != p && Num[v] % 2 == 0) {
            ans++;
        }
    } 
    for (auto v : G[u]) {
        if (v != p) dfs2(v, u);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    if (n & 1) {
        cout << -1 << endl; return 0;
    }

    dfs(1, 0); dfs2(1, 0);
    cout << ans << endl;
    
    return 0;
} 