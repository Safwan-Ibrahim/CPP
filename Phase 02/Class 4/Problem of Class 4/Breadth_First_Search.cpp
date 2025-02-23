// Created on: 2025-02-22 02:35
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 105;
vector<int> G[N];
int D[N];
bool Vs[N];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int u, k; cin >> u >> k;
        while(k--) {
            int v; cin >> v;
            G[u].push_back(v);
        }
    }

    queue<int>Q; Q.push(1);
    Vs[1] = true;
    
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto v : G[u]) {
            if (!Vs[v]) {
                Q.push(v);
                D[v] = D[u] + 1;
                Vs[v] = true;
            }
        }
    }

    cout << 1 << " " << 0 << endl;
    for (int i = 2; i <= n; i++) {
        cout << i << " " << (D[i] ? D[i] : -1) << endl;
    }
    
    return 0;
} 