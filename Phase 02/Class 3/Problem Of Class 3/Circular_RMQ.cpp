// Created on: 2025-02-01 22:29
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 9;
int A[N];
const ll inf = 1e18;

struct STL {
    #define lc (node << 1)
    #define rc ((node << 1) + 1)
    long long T[4 * N], Lazy[4 * N];
    STL() {
        memset(T, 0, sizeof T);
        memset(Lazy, 0, sizeof Lazy);
    }
    inline void push(int node, int b, int e) { // change this
        if (Lazy[node] == 0) {
            return;
        }
        T[node] = T[node] + Lazy[node];
        if (b != e) {
            Lazy[lc] = Lazy[lc] + Lazy[node];
            Lazy[rc] = Lazy[rc] + Lazy[node];
        }
        Lazy[node] = 0;
    }
    inline long long combine(long long a, long long b) { // change this
        return min(a, b);
    }
    inline void pull(int node) { // change this
        T[node] = min(T[lc], T[rc]);
    }
    void build(int node, int b, int e) {
        Lazy[node] = 0; // change this
        if (b == e) {
            T[node] = A[b];
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
            Lazy[node] = v; // set lazy
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
        if (i > e || b > j) {
            return inf; // return null
        }
        if (i <= b && e <= j) {
            return T[node];
        }
        int mid = (b + e) >> 1;
        return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
    }
} T;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    T.build(1, 1, n);
    int q; cin >> q;
    cin.ignore();
    while(q--) {
        string Line; 
        getline(cin, Line);
        int l, r, v;
        stringstream  scin(Line);
        scin >> l >> r;
        l++, r++;
        if (scin >> v) {
            if (l > r) {
                T.upd(1, 1, n, 1, r, v);
                T.upd(1, 1, n, l, n, v);
            }
            else {
                T.upd(1, 1, n, l, r, v);
            }
        }
        else {
            if (l > r) {
                cout << min(T.query(1, 1, n, 1, r), T.query(1, 1, n, l, n)) << endl;   
            }
            else {
                cout << T.query(1, 1, n, l, r) << endl;
            } 
        }
    }
    
    return 0;
} 