// Created on: 2025-08-10 22:16
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n; vector<int> G[nn];

int ans, root;
void dfs(int u, int p) {
    bool call = false;
    for (auto v : G[u]) {
        if (v != p) {
            call = true;
            dfs(v, u);
        }
    }
    if (!call && p != root && p != 0) {
        ans++;
    }
}

void Try() {
    cin >> n;
    
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    root = 1; int mx = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (auto v : G[i]) {
            cnt += G[v].size() == 1;
        }
        if (cnt > mx) mx = cnt, root = i;        
    }

    dfs(root, 0);
    cout << ans << endl;

    for (int i = 1; i <= n; i++) {
        G[i].clear();
    }
    ans = 0;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 