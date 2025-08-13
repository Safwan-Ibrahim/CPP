// Created on: 2025-08-01 15:58
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
vector<int> G[nn];
int n, In[nn], Mxh[nn];
bool Vs[nn];

void dfs(int u) {
    Vs[u] = true;
    Mxh[u] = 1;
    for (auto v : G[u]) {
        if (!Vs[v]) {
            dfs(v);
        }
        Mxh[u] = max(Mxh[u], Mxh[v] + 1);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        while(k--) {
            int v; cin >> v;
            G[i].push_back(v);
            In[v]++;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (In[i] == 0) {
            dfs(i); 
            if (Mxh[i] == n) {
                cout << 1 << endl; return 0;
            }
            break;
        }
    }
    cout << 0 << endl;

    return 0;
} 