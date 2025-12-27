// Created on: 2025-05-05 07:48
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 5e5 + 8;
vector<int> G[nn];
int n, m, Ans[nn];
bool Vs[nn];
vector<int>V;

void dfs(int u) {
    Vs[u] = true;
    V.push_back(u);
    for (auto v : G[u]) {
        if (!Vs[v]) {
            dfs(v);
        }
    }
}

void calculte() {
    int cnt = V.size();
    for (auto x : V) {
        Ans[x] = cnt;
    }
    V.clear();
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    while(m--) {
        int k; cin >> k;
        vector<int>V;
        while(k--) {
            int x; cin >> x;
            V.push_back(x);
        }
        for (int i = 0; i + 1 < V.size(); i++) {
            int u = V[i], v = V[i + 1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (Ans[i] == 0) {
            dfs(i);
            calculte();
        } 
        cout << Ans[i] << " ";
    }
    cout << endl;
    
    return 0;
} 