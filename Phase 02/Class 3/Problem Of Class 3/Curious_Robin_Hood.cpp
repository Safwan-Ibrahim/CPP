// Created on: 2025-01-25 20:32
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 9;
int A[nn];

struct ST {
    ll T[4 * nn];
    static const int inf = 1e9;
    ll given = 0;
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
        T[node] = T[l] + T[r];
    }

    ll query(int node, int b, int e, int i, int j) {
        if (i <= b && j >= e) {
            return T[node];
        }
        else if (b > j || e < i) {
            return 0;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
    }

    void upd(int node, int b, int e, int id, int x) {
        if (b > id || e < id) {
            return;
        }
        if (b == e && b == id) {
            if (x == 0) {
                given = T[node];
                T[node] = 0;
            }
            else {
                T[node] += x;
            }
            return;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        upd(l, b, mid, id, x);
        upd(r, mid + 1, e, id, x);
        T[node] = T[l] + T[r];
    }
}T;

void solve() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    T.build(1, 1, n);
    
    while(q--) {
        int t; cin >> t;
        if (t == 1) {
            int id; cin >> id;
            T.upd(1, 1, n, id + 1, 0);
            cout << T.given << endl;
        }
        else if (t == 2) {
            int id, v; cin >> id >> v;
            T.upd(1, 1, n, id + 1, v);
        }
        else {
            int i, j; cin >> i >> j;
            cout << T.query(1, 1, n, i + 1, j + 1) << endl;
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":" << endl;
        solve();
    }
    return 0;
} 