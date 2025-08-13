// Created on: 2025-01-25 15:53
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 9;
int A[nn];

struct ST {
    int T[4 * nn];
    static const int inf = 1e9;
    ST() {
        memset(T, 0, sizeof T);
    }
    void build(int node, int b, int e) {
        if (b == e) {
            T[node] = A[b];
            return;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        T[node] = min(T[l], T[r]);
    }

    int query(int node, int b, int e, int i, int j) {
        if (i <= b && j >= e) {
            return T[node];
        }
        else if (b > j || e < i) {
            return inf;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        return min(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
    }

    void upd(int node, int b, int e, int id, int x) {
        if (b > id || e < id) {
            return;
        }
        if (b == e && b == id) {
            T[node] = x;
            return;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        upd(l, b, mid, id, x);
        upd(r, mid + 1, e, id, x);
        T[node] = min(T[l], T[r]);
    }
}T;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    T.build(1, 1, n);

    while(q--) {
        int t, i, j; cin >> t >> i >> j;
        i++;
        if (t == 1) {
            T.upd(1, 1, n, i, j);
        }
        else {
            cout << T.query(1, 1, n, i, j) << endl; 
        }
    }

    return 0;
} 