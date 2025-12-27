// Created on: 2025-12-07 20:23
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, q, V[nn], F1[nn], F2[nn], Tin[nn], Tout[nn], timer = 1;
vector<int> G[nn];

struct ST {
    static const int inf = 1e9;
    vector<ll> T;
    int n;

    ST(int pn) : n(pn) {
        T.assign(4 * (n + 2), 0);
    }

    void build(int node, int b, int e, bool f) {
        if (b == e) {
            T[node] = (f ? F1[b] : F2[b]);
            return;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        build(l, b, mid, f);
        build(r, mid + 1, e, f);
        T[node] = T[l] + T[r];
    }

    ll query(int node, int b, int e, int i, int j) {
        if (i <= b && j >= e) return T[node];
        if (b > j || e < i) return 0;
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
    }

    void upd(int node, int b, int e, int id, int x) {
        if (b > id || e < id) return;
        if (b == e && b == id) {
            T[node] = x;
            return;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        upd(l, b, mid, id, x);
        upd(r, mid + 1, e, id, x);
        T[node] = T[l] + T[r];
    }
};

void dfs(int u, int p) {
    Tin[u] = timer++;

    F1[Tin[u]] = V[u];

    for (auto v : G[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }

    Tout[u] = timer - 1;
    F2[Tout[u]] = V[u];
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> V[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(1, 0); 
    ST T(n), T2(n);

    T.build(1, 1, n, 1);
    T2.build(1, 1, n, 0);

    while (q--) {
        int u; cin >> u;
        ll sum = T.query(1, 1, n, 1, Tin[u]) - T2.query(1, 1, n, 1, Tin[u] - 1);
        cout << sum << endl;
    }
    
    return 0;
} 