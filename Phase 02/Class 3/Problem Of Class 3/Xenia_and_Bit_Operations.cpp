// Created on: 2025-01-27 18:36
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = (1 << 17) + 10;
int A[N];

struct ST {
    int T[4 * N];
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
        int len = __lg(e - b + 1);
        if (len & 1) {
            T[node] = T[l] | T[r];
        }
        else {
            T[node] = T[l] ^ T[r];
        }
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
        int len = log2(e - b + 1);
        if (len & 1) {
            T[node] = T[l] | T[r];
        }
        else {
            T[node] = T[l] ^ T[r];
        }
    }
    int ans() {
        return T[1];
    }
}T;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n, m; cin >> n >> m;
    n = 1 << n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    T.build(1, 1, n);
    while(m--) {
        int id, v; cin >> id >> v;
        T.upd(1, 1, n, id, v);
        cout << T.ans() << endl;
    }
    
    return 0;
} 