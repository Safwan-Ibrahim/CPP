// Created on: 2025-07-04 23:12
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, m, A[nn];

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
        T[node] = max(T[l], T[r]);
    }

    int query(int node, int b, int e, int i, int j) {
        if (i <= b && j >= e) {
            return T[node];
        }
        else if (b > j || e < i) {
            return 0;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        return max(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
    }
}T;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> A[i];
    }
    T.build(1, 1, m);

    int q; cin >> q;
    while(q--) {
        int xs, ys, xf, yf, k; cin >> xs >> ys >> xf >> yf >> k;
        if (abs(xs - xf) % k != 0 || abs(ys - yf) % k != 0) {
            cout << "NO\n"; continue;
        }
        if (ys > yf) swap(ys, yf);
        int df = n - xs;
        int mx = n - df % k;
        if (T.query(1, 1, m, ys, yf) < mx) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    
    return 0;
} 