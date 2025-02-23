// Created on: 2025-01-26 12:04
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 9;
int A[N];

struct mp {
    int left_value, right_value, left_count, right_count, mx_count;
};

struct ST {
    mp T[4 * N];
    static const int inf = -1e9;

    mp merge(mp l, mp r) {
        if (l.left_value == -1) {
            return r;
        }
        if (r.left_value == -1) {
            return l;
        }
        mp ans;
        ans.left_value = l.left_value;
        ans.right_value = r.right_value;
        ans.left_count = l.left_count;
        ans.right_count = r.right_count;
        if (l.left_value == r.left_value) {
            ans.left_count += r.left_count;
        }
        if (r.right_value == l.right_value) {
            ans.right_count += l.right_count;
        }
        ans.mx_count = max(r.mx_count, l.mx_count);
        if (l.right_value == r.left_value) {
            ans.mx_count = max(ans.mx_count, l.right_count + r.left_count);
        }
        return ans;
    }

    void build(int node, int b, int e) {
        if (b == e) {
            T[node].left_value = T[node].right_value = A[b];
            T[node].left_count = T[node].right_count = T[node].mx_count = 1;
            return;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        T[node] = merge(T[l], T[r]);
    }

    mp query(int node, int b, int e, int i, int j) {
        if (i <= b && j >= e) {
            return T[node];
        }
        else if (b > j || e < i) {
            return {-1, -1, -1, -1, -1};
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
    }

}T;

void solve() {
    int n, c, q; cin >> n >> c >> q;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    T.build(1, 1, n);
    while(q--) {
        int i, j; cin >> i >> j;
        cout << T.query(1, 1, n, i, j).mx_count << endl;
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