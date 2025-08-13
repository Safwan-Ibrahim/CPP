// Created on: 2025-03-28 08:22
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8, M = 1e9 + 7;
vector<int> G[nn];
int Ans[nn][2], Ways[nn][2];

int ways(int u, int p, bool last_black) {
    if (Ans[u][last_black] != -1) {
        return Ans[u][last_black];
    }

    int ans_black = 1, ans_white = 1;
    for (auto v : G[u]) {
        if (v != p) {
            ans_white = 1LL * ans_white * ways(v, u, 0) % M;
            if (!last_black) {
                ans_black = 1LL * ans_black * ways(v, u, 1) % M;
            }
        } 
    }
    
    int ans = ans_white;
    if (!last_black) {
        ans = (ans_white + ans_black) % M;
    }
    return Ans[u][last_black] = ans;
}

void dfs(int u, int p) {
    Ways[u][0] = 1, Ways[u][1] = 1;
    for (auto v : G[u]) {
        if (v != p) {
            dfs(v, u);
            Ways[u][0] = 1LL * Ways[u][0] * ((Ways[v][0] + Ways[v][1]) % M) % M;
            Ways[u][1] = 1LL * Ways[u][1] * Ways[v][0] % M;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // memset(Ans, -1, sizeof Ans);
    // cout << ways(1, 0, 0) << endl;
    dfs(1, 0);
    cout << (Ways[1][0] + Ways[1][1]) % M << endl;

    
    return 0;
} 