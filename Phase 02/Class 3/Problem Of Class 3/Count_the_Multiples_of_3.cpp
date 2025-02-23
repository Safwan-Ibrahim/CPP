// Created on: 2025-01-28 12:11
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 7;

struct STL {
    #define lc (node << 1)
    #define rc ((node << 1) + 1)
    int lazy[4 * N];
    array<int, 5> T[N * 4];

    inline void push(int node, int b, int e) { // change this
        if (lazy[node] == 0)
            return;
        int up = lazy[node];
        array<int, 5>ans;
        for (int i = 0; i < 4; i++) {
            ans[i] = 0; 
        }
        for (int i = 0; i < 4; i++) {
            ans[(i + up) % 3] += T[node][i]; 
        }
        for (int i = 0; i < 4; i++) {
            T[node][i] = ans[i]; 
        }
        if (b != e) {
            lazy[lc] = lazy[lc] + lazy[node];
            lazy[rc] = lazy[rc] + lazy[node];
        }
        lazy[node] = 0;
    }
    array<int, 5> merge(array<int, 5>a, array<int, 5>b) { // change this
        array<int, 5>ans;
        for (int i = 0; i < 5; i++) {
            ans[i] = a[i] + b[i];
        }
        return ans;
    }
    void build(int node, int b, int e) {
        lazy[node] = 0; // change this
        if (b == e) {
            T[node] = {1, 0, 0, 0, 0};
            return;
        }
        int mid = (b + e) >> 1;
        build(lc, b, mid);
        build(rc, mid + 1, e);
        T[node] = merge(T[lc], T[rc]);
    }
    void upd(int node, int b, int e, int i, int j) {
        push(node, b, e);
        if (j < b || e < i)
            return;
        if (i <= b && e <= j) {
            lazy[node] = 1; // set lazy
            push(node, b, e);
            return;
        }
        int mid = (b + e) >> 1;
        upd(lc, b, mid, i, j);
        upd(rc, mid + 1, e, i, j);
        T[node] = merge(T[lc], T[rc]);
    }
    array<int, 5> query(int node, int b, int e, int i, int j) {
        push(node, b, e);
        if (i > e || b > j)
            return {0, 0, 0, 0, 0}; // return null
        if (i <= b && e <= j)
            return T[node];
        int mid = (b + e) >> 1;
        return merge(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
    }
} T;

void solve() {
    int n, q; cin >> n >> q;
    T.build(1, 1, n);

    while(q--) {
        int ty, l, r; cin >> ty >> l >> r;
        l++, r++;
        if (ty) {
            cout << T.query(1, 1, n, l, r)[0] << endl;
        }
        else {
            T.upd(1, 1, n, l, r);
        }
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";
        solve();
    }
    return 0;
} 