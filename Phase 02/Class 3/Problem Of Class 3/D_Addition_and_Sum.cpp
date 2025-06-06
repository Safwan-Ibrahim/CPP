// Created on: 2025-01-28 09:54
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 9;
int A[N];

struct STL {
    #define lc (node << 1)
    #define rc ((node << 1) + 1)
    long long T[4 * N], Lazy[4 * N];
    STL() {
        memset(T, 0, sizeof T);
        memset(Lazy, 0, sizeof Lazy);
    }
    inline void push(int node, int b, int e) { // change this
        if (Lazy[node] == 0)
            return;
        T[node] = T[node] + (Lazy[node] * (e - b + 1));
        if (b != e) {
            Lazy[lc] += Lazy[node];
            Lazy[rc] += Lazy[node];
        }
        Lazy[node] = 0;
    }
    inline long long combine(long long a, long long b) { // change this
        return a + b;
    }
    inline void pull(int node) { // change this
        T[node] = T[lc] + T[rc];
    }
    void build(int node, int b, int e) {
        if (b == e) {
            T[node] = 0;
            return;
        }
        int mid = (b + e) >> 1;
        build(lc, b, mid);
        build(rc, mid + 1, e);
        pull(node);
    }
    void upd(int node, int b, int e, int i, int j,long long v) {
        push(node, b, e);
        if (j < b || e < i)
            return;
        if (i <= b && e <= j) {
            Lazy[node] += v;
            push(node, b, e);
            return;
        }
        int mid = (b + e) >> 1;
        upd(lc, b, mid, i, j, v);
        upd(rc, mid + 1, e, i, j, v);
        pull(node);
    }
    long long query(int node, int b, int e, int i, int j) {
        push(node, b, e);
        if (i > e || b > j)
            return 0; // return null
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