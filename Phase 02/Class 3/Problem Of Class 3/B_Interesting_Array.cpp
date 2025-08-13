// Created on: 2025-01-31 21:28
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 9;
int A[nn], L[nn], R[nn], Q[nn];

struct STL {
    #define lc (node << 1)
    #define rc ((node << 1) + 1)
    long long T[4 * nn], Lazy[4 * nn];

    STL() {
        memset(T, 0, sizeof T);
        memset(Lazy, 0, sizeof Lazy);
    }
    
    inline void push(int node, int b, int e) { // change this
        if (Lazy[node] == 0) {
            return;
        }
        T[node] = T[node] | Lazy[node];
        if (b != e) {
            Lazy[lc] = Lazy[lc] | Lazy[node];
            Lazy[rc] = Lazy[rc] | Lazy[node];
        }
        Lazy[node] = 0;
    }

    inline int combine(int a, int b) { // change this
        return a & b;
    }

    inline void pull(int node) { 
        T[node] = T[lc] & T[rc];
    }

    void upd(int node, int b, int e, int i, int j, int v) {
        push(node, b, e);
        if (j < b || e < i) {
            return;
        }
        if (i <= b && e <= j) {
            Lazy[node] = v; 
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
            return ~(0);
        if (i <= b && e <= j)
            return T[node];
        int mid = (b + e) >> 1;
        return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
    }
} T;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> L[i] >> R[i] >> Q[i];
        T.upd(1, 1, n, L[i], R[i], Q[i]);
    }

    for (int i = 1; i <= m; i++) {
        if (T.query(1, 1, n, L[i], R[i]) != Q[i]) {
            cout << "NO\n";
            return 0;
        } 
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << T.query(1, 1, n, i, i) << " ";
    }
    cout << endl;
    
    return 0;
} 