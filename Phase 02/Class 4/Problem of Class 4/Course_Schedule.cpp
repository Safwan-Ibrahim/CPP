// Created on: 2025-03-14 02:17
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 8;
vector<int>G[N];
int Indeg[N];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n, m; cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        Indeg[v]++;
    }

    stack<int>Zero;
    for (int i = 1; i <= n; i++) {
        if (Indeg[i] == 0) {
            Zero.push(i);
        }
    }

    vector<int>Ans;
    while(Ans.size() < n) {
        if (Zero.empty()) {
            cout << "IMPOSSIBLE\n"; return 0;
        }
        int u = Zero.top();
        Zero.pop();
        Ans.push_back(u);

        for (auto v : G[u]) {
            Indeg[v]--;
            if (Indeg[v] == 0) {
                Zero.push(v);
            }
        }
    }

    for (auto x : Ans) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
} 