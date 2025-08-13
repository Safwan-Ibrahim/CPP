// Created on: 2025-01-27 23:49
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 9, inf = -1e9;
int A[nn];

struct STL {
    #define lc (n << 1)
    #define rc ((n << 1) + 1)
    int t[4 * nn], lazy[4 * nn];
    STL() {
        memset(t, 0, sizeof t);
        memset(lazy, 0, sizeof lazy);
    }
    inline void push(int n, int b, int e) { // change this
        if (lazy[n] == 0)
            return;
        t[n] = max(t[n], lazy[n]);
        if (b != e) {
            lazy[lc] = max(lazy[lc], lazy[n]);
            lazy[rc] = max(lazy[rc], lazy[n]);
        }
        lazy[n] = 0;
    }
    inline int combine(int a, int b) { // change this
        return max(a, b);
    }
    inline void pull(int n) { // change this
        t[n] = max(t[lc], t[rc]);
    }
    void build(int n, int b, int e) {
        lazy[n] = 0; // change this
        if (b == e) {
            t[n] = A[b];
            return;
        }
        int mid = (b + e) >> 1;
        build(lc, b, mid);
        build(rc, mid + 1, e);
        pull(n);
    }
    void upd(int n, int b, int e, int i, int j, int v) {
        push(n, b, e);
        if (j < b || e < i)
            return;
        if (i <= b && e <= j) {
            lazy[n] = v; // set lazy
            push(n, b, e);
            return;
        }
        int mid = (b + e) >> 1;
        upd(lc, b, mid, i, j, v);
        upd(rc, mid + 1, e, i, j, v);
        pull(n);
    }
    int query(int n, int b, int e, int i, int j) {
        push(n, b, e);
        if (i > e || b > j)
            return inf; // return null
        if (i <= b && e <= j)
            return t[n];
        int mid = (b + e) >> 1;
        return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
    }
} T;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n, m; cin >> n >> m;
    while(m--) {
        int t; cin >> t;
        if (t == 1) {
            int i, j, x; cin >> i >> j >> x;
            i++;
            T.upd(1, 1, n, i, j, x);
        }
        else {
            int id; cin >> id;
            id++;
            cout << T.query(1, 1, n, id, id) << endl;
        }
    }
    
    return 0;
} 