// Created on: 2025-08-01 14:03
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int A[nn];

struct STL {
    #define lc (node << 1)
    #define rc ((node << 1) + 1)
    long long T[4 * nn], Lazy[4 * nn];
    STL() {
        memset(T, 0, sizeof T);
        memset(Lazy, 0, sizeof Lazy);
    }
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
            T[node] = A[b];
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

string S;
int get_min(int need) {
    int ans = 1;
    for (int i = 0; i < S.size(); i++) {
        int x = S[i] - '0';
        if (x == need) {
            ans++;
            if (i + 1 < S.size()) need = 1 ^ (S[i + 1] - '0'), i++;
        }
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> S;
    cout << min(get_min(1), get_min(0)) << endl;
    return 0;
} 