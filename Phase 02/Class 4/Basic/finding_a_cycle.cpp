// Created on: 2025-02-21 05:01
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 8;
vector<int> G[N];
int Col[N], Par[N];
bool cycle;

void dfs(int u) {
    Col[u] = 1;
    for (auto x : G[u]) {
        if (Col[x] == 0) {
            Par[x] = u;
            dfs(x);
        }
        else if (Col[x] == 1) {
            cycle = true;
        }
    }
    Col[u] = 2;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n, m; cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
    }

    cycle = false;
    for (int i = 1; i <= n; i++) {
        if (Col[i] == 0) {
            dfs(1);
        }
    }
    cout << boolalpha << cycle << endl;

    return 0; 
} 