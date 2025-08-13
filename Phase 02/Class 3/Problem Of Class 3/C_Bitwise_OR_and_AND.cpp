// Created on: 2025-01-28 11:11
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 9, inf = ~(0);

struct STL {
    #define lc (node << 1)
    #define rc ((node << 1) + 1)
    int T[4 * nn], lazy[4 * nn];
    STL() {
        memset(T, 0, sizeof T);
        memset(lazy, 0, sizeof lazy);
    }
    inline void push(int node, int b, int e) { // change this
        if (lazy[node] == 0)
            return;
        T[node] |= lazy[node];
        if (b != e) {
            lazy[lc] |= lazy[node];
            lazy[rc] |= lazy[node];
        }
        lazy[node] = 0;
    }
    inline int combine(long long a, long long b) { // change this
        return a & b;
    }
    inline void pull(int node) { // change this
        T[node] = T[lc] & T[rc];
    }
    void build(int node, int b, int e) {
        lazy[node] = 0; // change this
        if (b == e) {
            T[node] = 0;
            return;
        }
        int mid = (b + e) >> 1;
        build(lc, b, mid);
        build(rc, mid + 1, e);
        pull(node);
    }
    void upd(int node, int b, int e, int i, int j, int v) {
        push(node, b, e);
        if (j < b || e < i)
            return;
        if (i <= b && e <= j) {
            lazy[node] = v; // set lazy
            push(node, b, e);
            return;
        }
        int mid = (b + e) >> 1;
        upd(lc, b, mid, i, j, v);
        upd(rc, mid + 1, e, i, j, v);
        pull(node);
    }
    int query(int node, int b, int e, int i, int j) {
        push(node, b, e);
        if (i > e || b > j)
            return inf; // return null
        if (i <= b && e <= j)
            return T[node];
        int mid = (b + e) >> 1;
        return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
    }
} T;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n, q; cin >> n >> q;

    T.build(1, 1, n);

    while(q--) {
        int ty; cin >> ty;
        if (ty == 1) {
            int l, r, v; cin >> l >> r >> v;
            l++;
            T.upd(1, 1, n, l, r, v);
        }
        else {
            int l, r; cin >> l >> r;
            l++;
            cout << T.query(1, 1, n, l, r) << endl;
        }
    }

    
    
    return 0;
} 