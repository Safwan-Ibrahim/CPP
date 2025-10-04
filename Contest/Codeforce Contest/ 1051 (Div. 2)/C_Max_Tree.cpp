// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, x, y, u, v, In[nn];
vector<int> G[nn];

void Try() {
    cin >> n;

    for (int i = 1; i < n; i++) {
        cin >> u >> v >> x >> y;
        if (u > v) swap(u, v);
        if (y > x) {
            G[u].push_back(v);
            In[v]++;
        }
        else {
            G[v].push_back(u);
            In[u]++;
        }
    }
    
    vector<int> Ans(n + 1, 0);

    vector<int> Z;
    for (int i = 1; i <= n; i++) {
        if (!In[i]) {
            Z.push_back(i);
        }
    }

    int cnt = 1;
    while (Z.size()) {
        int u = Z.back();
        Z.pop_back();
        Ans[u] = cnt++;

        for (auto v : G[u]) {
            In[v]--;
            if (!In[v]) Z.push_back(v);
        }
    }

    assert(cnt == n + 1);

    for (int i = 1; i <= n; i++) {
        cout << Ans[i] << " ";
        In[i] = 0;
        G[i].clear();
    }

    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 