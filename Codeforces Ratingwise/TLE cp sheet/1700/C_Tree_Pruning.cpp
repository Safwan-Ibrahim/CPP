// Created on: 2025-06-27 18:03
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int nn = 5e5 + 17;
vector<int> G[nn];
int n, Dept[nn], Mx[nn];
map<int, vector<int>>Mp;

void dfs(int u, int p) {
    bool call = false;
    for (auto v : G[u]) {
        if (v != p) {
            Dept[v] = Dept[u] + 1;
            dfs(v, u);
            Mx[u] = max(Mx[u], Mx[v]);
            call = true;
        }
    }
    if (!call) Mx[u] = Dept[u];
    Mp[Dept[u]].push_back(u);
}

void Try() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    } 

    dfs(1, 0);
    o_set<pair<int, int>>St;
    int mx = 0;
    int cnt = 1;
    for (auto [dept, vec] : Mp) {
        for (auto v : vec) {
            St.insert({Mx[v], cnt++});
        }
        int have = St.size() - St.order_of_key({dept, 0});
        mx = max(mx, have);
    }

    cout << n - mx << endl;

    for (int i = 1; i <= n; i++) {
        G[i].clear();
        Mx[i] = Dept[i] = 0;
    }
    Mp.clear();
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 