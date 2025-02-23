// Created on: 2025-02-21 22:09
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 8;
vector<int> G[N];
bool Cat[N];
int Mx[N], CC[N], n, m, cnt;

void dfs(int u, int p) {
    if (Cat[u]) {
        CC[u] += CC[p] + 1;
    }
    bool call = false;
    Mx[u] = max(CC[u], Mx[p]);
    for (auto x : G[u]) {
        if (x != p) {
            call = true;
            dfs(x, u);
        }
    }
    if (!call && Mx[u] <= m) {
        cnt++;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> Cat[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1, 0);
    
    cout << cnt << endl;

    return 0;
} 