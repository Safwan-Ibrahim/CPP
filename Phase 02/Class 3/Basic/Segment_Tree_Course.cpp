#include<bits/stdc++.h>
using namespace std;

const int nn = 3e5 + 9;
int A[nn];

struct ST {
    int T[4 * nn];
    static const int inf = 1e9;
    ST() {
        memset(T, 0, sizeof T);
    }
    void build(int n, int b, int e) {
        if (b == e) {
        T[n] = A[b];
        return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        T[n] = max(T[l], T[r]); // change this
    }
    void upd(int n, int b, int e, int i, int x) {
        if (b > i || e < i) return;
        if (b == e && b == i) {
        T[n] = x; // update
        return;
        }
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        upd(l, b, mid, i, x);
        upd(r, mid + 1, e, i, x);
        T[n] = max(T[l], T[r]); // change this
    }
    int query(int n, int b, int e, int i, int j) {
        if (b > j || e < i) return -inf; // return appropriate value
        if (b >= i && e <= j) return T[n];
        int mid = (b + e) >> 1, l = n << 1, r = l | 1;
        return max(query(l, b, mid, i, j), query(r, mid + 1, e, i, j)); // change this
    }
}T;

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n = 5;
    for (int i = 1; i <= n; i++) {
        A[i] = i;
    }
    ST T2;
    T.build(1, 1, n); // building the segment tree
    T.upd(1, 1, n, 2, 10); // assiging 10 to the index 2 (A[2] := 10)
    cout << T.query(1, 1, n, 1, 5) << '\n'; // range max query on the segment [1, 5]
    T2.build(1, 1, n); // building the segment tree
    T2.upd(1, 1, n, 2, 10); // assiging 10 to the index 2 (A[2] := 10)
    cout << T2.query(1, 1, n, 1, 5) << '\n'; // range max query on the segment [1, 5]

    return 0;
}