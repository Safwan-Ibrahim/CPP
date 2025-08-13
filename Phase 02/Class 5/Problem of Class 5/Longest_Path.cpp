// Created on: 2025-03-28 06:50
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8;
vector<int>G[nn];
int Ans[nn];

int max_path(int u) {
    if (Ans[u] != -1) {
        return Ans[u];
    }
    int ans = 1;
    for (auto v : G[u]) {
        ans = max(ans, 1 + max_path(v));
    }
    //cerr << u << " " << ans << endl;
    return Ans[u] = ans;
}

int32_t main() {          
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m; cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
    }

    memset(Ans, -1, sizeof Ans);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, max_path(i));
    }

    cout << ans - 1 << endl;
    
    return 0;
} 