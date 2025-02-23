// Created on: 2025-02-12 17:32
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 9;
vector<int> G[N];
int In[N];
bool Vs[N];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n, m; cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        In[v]++;
    }

    vector<int>Ans;
    vector<int>Z;
    for (int i = 1; i <= n; i++) {
        if (In[i] == 0) {
            Z.push_back(i);;
        }
    }

    while(Ans.size() < n) {
        if (Z.empty()) {
            cout << "Impossible\n"; return 0;
        }
        int cur = Z.back(); 
        Z.pop_back();

        Ans.push_back(cur);
        for (auto x : G[cur]) {
            In[x]--;
            if (In[x] == 0) {
                Z.push_back(x);
            }
        }
    }

    for (auto x : Ans) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
} 