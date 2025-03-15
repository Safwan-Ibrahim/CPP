// Created on: 2025-02-21 06:44
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 8;
vector<int> G[N];
int Indeg[N];
bool Vs[N];

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        Indeg[v]++;
    }

    vector<int>Ans, Zero;
    for (int i = 1; i <= n; i++) {
        if (Indeg[i] == 0) {
            Vs[i] = true;
            Zero.push_back(i);
        }
    }
    while(Ans.size() < n) {
        if (Zero.empty()) {
            cout << "Impossible\n"; return 0;
        }

        int cur = Zero.back();
        Zero.pop_back();

        Ans.push_back(cur);
        for (auto v : G[cur]) {
            Indeg[v]--;
            if (!Vs[v] && Indeg[v] == 0) {
                Vs[v] = true;
                Zero.push_back(v);
            }
        }
    }

    for (auto x : Ans) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
} 