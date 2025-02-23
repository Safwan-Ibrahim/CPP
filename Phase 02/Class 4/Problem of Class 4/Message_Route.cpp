// Created on: 2025-02-22 03:16
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 8;
vector<int> G[N];
vector<bool>Vs(N, false);
int P[N];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n, m; cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    queue<int>Q; Q.push(1);
    Vs[1] = true;

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto v : G[u]) {
            if (!Vs[v]) {
                Vs[v] = true;
                P[v] = u;
                Q.push(v);
            }
        }
    }

    if (!Vs[n]) {
        cout << "IMPOSSIBLE\n"; return 0;
    }

    int u = n;
    vector<int>Ans{n};
    while(P[u] != 0) {
        Ans.push_back(P[u]);
        u = P[u];
    }

    cout << Ans.size() << endl;
    reverse(Ans.begin(), Ans.end());
    for (int i = 0; i < Ans.size(); i++) {
        cout << Ans[i] << " ";
    }
    cout << endl;
    
    return 0;
} 