// Created on: 2025-01-30 22:49
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 9;
int A[N], n;

struct bits {
    int Cnt[21];
    bits() {
        memset(Cnt, 0, sizeof Cnt);
    }
};

struct STL {
    #define lc (node << 1)
    #define rc ((node << 1) + 1)
    int Lazy[4 * N];
    bits T[4 * N];
    STL() {
        memset(Lazy, 0, sizeof Lazy);
    }

    inline void push(int node, int b, int e) {
        if (Lazy[node] == 0)
            return;

        int ele = e - b + 1;
        for (int i = 0; i < 21; i++) {
            if (Lazy[node] >> i & 1) {
                T[node].Cnt[i] = ele - T[node].Cnt[i];
            }
        }

        if (b != e) {
            Lazy[lc] = Lazy[lc] ^ Lazy[node];
            Lazy[rc] = Lazy[rc] ^ Lazy[node];
        }
        Lazy[node] = 0;
    }

    bits combine(bits a, bits b) { 
        bits ans;
        for (int i = 0; i < 21; i++) {
            ans.Cnt[i] = a.Cnt[i] + b.Cnt[i];
        }
        return ans;

    }

    inline void pull(int node) { 
        for (int i = 0; i < 21; i++) {
            T[node].Cnt[i] = T[lc].Cnt[i] + T[rc].Cnt[i];
        }
    }

    void build(int node, int b, int e) {
        Lazy[node] = 0; 
        if (b == e) {
            bits bt;
            for (int i = 0; i < 21; i++) {
                if (A[b] >> i & 1) {
                    bt.Cnt[i] = 1;
                }
            }
            T[node] = bt;
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
            Lazy[node] = v; 
            push(node, b, e);
            return;
        }
        int mid = (b + e) >> 1;
        upd(lc, b, mid, i, j, v);
        upd(rc, mid + 1, e, i, j, v);
        pull(node);
    }

    bits query(int node, int b, int e, int i, int j) {
        push(node, b, e);
        if (i > e || b > j) {
            bits a;
            return a;
        }
        if (i <= b && e <= j)
            return T[node];
        int mid = (b + e) >> 1;
        return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
    }
} T;


int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    T.build(1, 1, n);
    int q; cin >> q;
    while(q--) {
        int ty; cin >> ty;
        if (ty == 1) {
            int l, r; cin >> l >> r;
            bits Ans = T.query(1, 1, n, l, r);
            ll sum = 0;
            for (int i = 0; i < 21; i++) {
                sum += 1LL * Ans.Cnt[i] * (1 << i);
            }
            cout << sum << endl;
        }
        else {
            int l, r, v; cin >> l >> r >> v;
            T.upd(1, 1, n, l, r, v);
        }
    }

    return 0;
} 