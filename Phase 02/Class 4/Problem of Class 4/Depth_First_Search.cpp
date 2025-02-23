// Created on: 2025-02-20 19:55
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 105;
vector<int> G[N];
bool Vs[N];
int S[N], F[N], ct = 1;

void dfs(int u) {
    Vs[u] = true;
    S[u] = ct++;
    for (auto x : G[u]) {
        if (!Vs[x]) {
            dfs(x);
        }
    }
    F[u] = ct++;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int u, k; cin >> u >> k;
        for (int j = 1; j <= k; j++) {
            int x; cin >> x;
            G[u].push_back(x);
        }
        sort(G[u].begin(), G[u].end());
    }

    for (int i = 1; i <= n; i++) {
        if (!Vs[i]) {
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << i << " " << S[i] << " " << F[i] << endl;
    }
    
    return 0;
} 