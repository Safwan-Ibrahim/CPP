// Created on: 2025-06-29 16:50
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, k, In[nn]; vector<int> G[nn];

void Try() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        int u, v;
        for (int j = 1; j <= n; j++) {
            cin >> v;
            if (j > 2) {
                G[u].push_back(v);
                In[v]++;
            }
            u = v;
        }
    }

    vector<int>Z;
    for (int i = 1; i <= n; i++) {
        if (In[i] == 0) Z.push_back(i);
    }
    
    bool yes = true;
    for (int i = 1; i <= n; i++) {
        if (Z.empty()) {
            yes = false; break;
        }
        int u = Z.back(); Z.pop_back();
        for (auto v : G[u]) {
            In[v]--;
            if (In[v] == 0) Z.push_back(v);
        }
    }

    cout << (yes ? "YES\n" : "NO\n");
    
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        In[i] = 0;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 