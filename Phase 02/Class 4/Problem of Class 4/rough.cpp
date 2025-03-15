// Created on: 2025-03-13 23:23
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 105;
vector<int>G[N], Ans; // clear it now
int n, m; // clear it now
bool Vs[N];

void dfs(int u) {
    Vs[u] = true;
    for (auto v : G[u]) {
        if (!Vs[v]) {
            dfs(v);
        }
    }   
    Ans.push_back(u);
}

void Try() {
    while (m--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
    }   

    for (int i = 1; i <= n; i++) {
        if (!Vs[i]) {
            dfs(i);
        }
    }

    reverse(Ans.begin(), Ans.end());
    for (auto x : Ans) {
        cout << x << " ";
    }
    cout << endl;

    Ans.clear();
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        Vs[i] = false;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    while(cin >> n >> m && (m != 0 || n != 0)) {
        Try();
    }
    return 0;
} 