// Created on: 2025-02-22 05:12
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1005;
vector<int> G[N]; // remember to clear in every try
vector<bool> H(N, true), Vs(N, false); // remember to clear in every try

void dfs(int u) {
    Vs[u] = true;
    for (auto v : G[u]) {
        if (!Vs[v]) {
            Vs[v] = true;
            dfs(v);
        }
    }
}

void Try() {
    int k, n, m; cin >> k >> n >> m;
    vector<int>A(k + 1, 0);
    for (int i = 1; i <= k; i++) {
        cin >> A[i];
    }
    
    while(m--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
    }

    for (int i = 1; i <= k; i++) {
        dfs(A[i]);
        for (int j = 1; j <= n; j++) {
            H[j] = H[j] & Vs[j];
            Vs[j] = false;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += H[i];
        H[i] = true;
        Vs[i] = false;
        G[i].clear();
    } 

    cout << cnt << endl;
    
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