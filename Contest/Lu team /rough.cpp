// Created on: 2025-04-11 15:59
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 7e5 + 8;
int A[N];

struct STL {
    #define lc (node << 1)
    #define rc ((node << 1) + 1)
    long long T[4 * N], Lazy[4 * N];
    // STL() {
    //     memset(T, 0, sizeof T);
    //     memset(Lazy, 0, sizeof Lazy);
    // }
    inline void push(int node, int b, int e) { // change this
        if (Lazy[node] == 0) {
            return;
        }
        T[node] = T[node] + Lazy[node] * (e - b + 1);
        if (b != e) {
            Lazy[lc] = Lazy[lc] + Lazy[node];
            Lazy[rc] = Lazy[rc] + Lazy[node];
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
        Lazy[node] = 0; // change this
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
            return 0; // return null
        }
        if (i <= b && e <= j) {
            return T[node];
        }
        int mid = (b + e) >> 1;
        return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
    }
} T;

void Try() {
    int n; cin >> n;
    vector<int>B(n + 1, 0), C(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        C[x] = i;
    }   

    T.build(1, 1, n);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int v = B[i];
        int id = C[v];
        ans += id - 1 - T.query(1, 1, n, id, id);
        T.upd(1, 1, n, id, n, 1);
    }    

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 