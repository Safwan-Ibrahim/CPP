// Created on: 2025-03-09 00:22
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 8;
vector<int> G[N];
bool ok;
int Col[N], Par[N], st, en;

void dfs(int u) {
    Col[u] = 1;
    for (auto v : G[u]) {
        if (Col[v] == 0) {
            Par[v] = u;
            dfs(v);
        }
        else {
            if (Col[u] == Col[v]) {
                st = u, en = v;
                ok = true;
            }
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

    ok = false;
    for (int i = 1; i <= n; i++) {
        if (Col[i] == 0) {
            dfs(i);
        }
    }

    cout << ok << endl;

    return 0;
} 