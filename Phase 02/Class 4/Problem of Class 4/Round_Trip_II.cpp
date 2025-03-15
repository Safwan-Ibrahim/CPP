// Created on: 2025-03-13 22:54
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 8;
vector<int>G[N], Ans;
bool Vs[N];
int Col[N], Par[N];
bool ok;

void dfs(int u, int p = 0) {
    if (ok) {
        return;
    }
    Par[u] = p;
    Vs[u] = true;
    Col[u] = 1; // 1 means it is active 
    for (auto v : G[u]) {
        if (ok) {
            return;
        }
        if (!Vs[v]) {
            dfs(v, u);
        }
        else if (Col[v] == 1) {
            ok = true;
            Ans.push_back(v);
            while(u != v) {
                Ans.push_back(u);
                u = Par[u];
            }
            Ans.push_back(v);
        }
    }
    Col[u] = 2; // 2 means it is inactive
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, m; cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (!Vs[i]) {
            dfs(i);
        }
    }

    if (!ok) {
        cout << "IMPOSSIBLE\n"; return 0;
    }

    cout << Ans.size() << endl;
    reverse(Ans.begin(), Ans.end());
    for (auto x : Ans) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
} 