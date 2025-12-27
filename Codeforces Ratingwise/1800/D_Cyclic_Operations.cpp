// Created on: 2025-12-08 05:03
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int n, k, Vs[nn], sz, In[nn], G[nn], cy;

set<int> St;
void dfs(int u) {
    if (Vs[u]) {
        sz = k; return;
    }

    St.insert(u);
    Vs[u] = true;

    int v = G[u];
    if (St.count(v)) {
        cy = v;
    }
    else dfs(v);

    if (cy != -1) sz++;
    if (cy == u) cy = -1;
}

void Try() {
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) {
        Vs[i] = 0;
        cin >> G[i];
    }

    for (int i = 1; i <= n; i++) {
        if (k == 1 && G[i] != i) {
            cout << "NO\n"; return;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (Vs[i]) continue;
        St.clear(); sz = 0, cy = -1;
        dfs(i);
        if (sz != k) {
            cout << "NO\n"; return;
        }
    }

    cout << "YES\n";

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 