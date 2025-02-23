// Created on: 2025-02-20 23:53
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 8;
vector<int> G[N];
bool Vs[N];
int n, m; 

void dfs(int u) {
    Vs[u] = true;
    for (auto x : G[u]) {
        if (!Vs[x]) {
            dfs(x);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int>Path;
    for (int i = 1; i <= n; i++) {
        if (!Vs[i]) {
            Path.push_back(i);
            dfs(i);
        }
    }

    cout << Path.size() - 1 << endl;
    for (int i = 0; i + 1 < Path.size(); i++) {
        cout << Path[i] << " " << Path[i + 1] << endl;
    }
    
    return 0;
} 