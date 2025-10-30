// Created on: 2025-06-21 15:49
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

#define dbg(x) cerr << #x << " -> " << x << endl; 

const int nn = 2e5 + 17;
set<int> G[nn], F[nn];

int cnt;
vector<int> Com;

void dfs(int u) {
    Com[u] = cnt;
    for (auto v : G[u]) {
        if (!Com[v]) dfs(v);
    }
}

void dfs2(int u) {
    Com[u] = cnt;
    for (auto v : F[u]) {
        if (!Com[v]) dfs2(v);
    }
}

void Try() {
    int n, m1, m2; cin >> n >> m1 >> m2;
    for (int i = 1; i <= m1; i++) {
        int u, v; cin >> u >> v;
        F[u].insert(v);
        F[v].insert(u);
    }
    for (int i = 1; i <= m2; i++) {
        int u, v; cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
    }
    
    
    Com = vector<int>(n + 10, 0);
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!Com[i]) {
            cnt++; dfs(i);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        vector<int>Tmp;
        for (auto v : F[i]) {
            if (Com[v] != Com[i]) Tmp.push_back(v);
        }
        for (auto x : Tmp) {
            F[i].erase(x);
        }
        ans += Tmp.size();
    }

    ans /= 2;
    //dbg(ans);
    
    int comp_f = cnt;
    Com = vector<int>(n + 10, 0);
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!Com[i]) {
            cnt++; dfs2(i);
        }
    }

    ans += abs(comp_f - cnt);
    cout << ans << endl;

    for (int i = 1; i <= n; i++) {
        F[i].clear(); 
        G[i].clear();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 