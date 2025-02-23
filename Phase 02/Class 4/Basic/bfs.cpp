// Created on: 2025-02-06 03:28
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 105;
vector<int> G[N]; // graph
bool Vs[N];
int Ds[N], Parent[N];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, m; cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    Vs[1] = 1;
    queue<int>Q;
    Q.push(1);

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop(); 
        for (auto x : G[u]) {
            if (!Vs[x]) {
                Parent[x] = u;
                Ds[x] = Ds[u] + 1;
                Vs[x] = 1;
                Q.push(x);
            }
        }
    }

    return 0;
} 