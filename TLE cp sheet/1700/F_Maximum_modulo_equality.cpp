// Created on: 2025-06-27 11:56
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn];

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
        T[node] = gcd(T[l], T[r]);
    }

    int query(int node, int b, int e, int i, int j) {
        if (i <= b && j >= e) {
            return T[node];
        }
        else if (b > j || e < i) {
            return 0;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        return gcd(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
    }

}T;

void Try() {
    cin >> n; n--;
    int q; cin >> q;
    int prev; cin >> prev;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        A[i] = abs(x - prev);
        prev = x;
    }
    if (n) T.build(1, 1, n);
    while(q--) {
        int l, r; cin >> l >> r;
        if (l == r || n == 0) cout << 0 << " ";
        else cout << T.query(1, 1, n, l, r - 1) << " ";
    }
    cout << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 