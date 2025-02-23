// Created on: 2025-02-01 22:05
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 9;
int A[N], n;

struct dept {
    int g, c;
};

struct ST {
    dept T[4 * N];
    static const int inf = 1e9;
    ST() {
        memset(T, 0, sizeof T);
    }

    dept merge(dept a, dept b) {
        dept ans;
        ans.g = gcd(a.g, b.g);
        ans.c = 0;
        if (ans.g == a.g) {
            ans.c += a.c;
        }
        if (ans.g == b.g) {
            ans.c += b.c;
        }
        return ans;
    }

    void build(int node, int b, int e) {
        if (b == e) {
            T[node].g = A[b];
            T[node].c = 1;
            return;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        T[node] = merge(T[l], T[r]);
    }

    dept query(int node, int b, int e, int i, int j) {
        if (i <= b && j >= e) {
            return T[node];
        }
        else if (b > j || e < i) {
            return {0, 0};
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
    }
}T;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    T.build(1, 1, n);
    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        cout << r - l + 1 - T.query(1, 1, n, l, r).c << endl;
    }
    
    
    return 0;
} 