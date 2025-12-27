// Created on: 2025-11-25 20:40
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int nn = 2010;
int n, P[nn], Cnt[nn], Need[nn], Ans[nn];
vector<int> G[nn];

void dfs(int u, int p) {
    Cnt[u] = 1;
    for (auto v : G[u]) {
        if (v != p) {
            dfs(v, u);
            Cnt[u] += Cnt[v];
        }
    }
}

bool pos() {
    dfs(0, 0);
    
    for (int i = 1; i <= n; i++) {
        if (Need[i] >= Cnt[i]) return false;
    }
    
    return true;
}

o_set<int> S;
void dfs2(int u, int p) {
    Ans[u] = *S.find_by_order(Need[u]);
    S.erase(S.find_by_order(Need[u]));
    
    for (auto v : G[u]) {
        if (v != p) {
            dfs2(v, u);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> P[i];
        G[P[i]].push_back(i);
        cin >> Need[i];
    }
    
    if (!pos()) {
        cout << "NO\n"; return 0;
    }

    for (int i = 1; i <= n; i++) {
        S.insert(i);
    }

    dfs2(G[0].front(), 0);
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << Ans[i] << " ";
    }

    cout << endl;
    return 0;
} 