// Created on: 2025-01-28 08:37
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 9;
char A[N], T[N * 4];
int Flip[N * 4];

void push(int node, int b, int e) {
    if (Flip[node] == 0) {
        return;
    }
    T[node] ^= (Flip[node] % 2 == 1 ? 1 : 0);
    if (b != e) {
        int l = 2 * node, r = 2 * node + 1;
        Flip[l] += Flip[node];
        Flip[r] += Flip[node];
    }
    Flip[node] = 0;
}

void build(int node, int b, int e) {
    Flip[node] = 0;
    if (b == e) {
        T[node] = A[b];
        return;
    }
    int mid = (b + e) / 2, l = 2 * node, r = 2 * node + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    return;
}

char query(int node, int b, int e, int id) {
    push(node, b, e);
    if (b == e) {
        return T[node];
    }
    int mid = (b + e) / 2, l = 2 * node, r = 2 * node + 1;
    if (b <= id && id <= mid) {
        return query(l, b, mid, id);
    }
    if (mid + 1 <= id && id <= e) {
        return query(r, mid + 1, e, id);
    }
    else {
        return '0';
    }
}

void upd(int node, int b, int e, int i, int j) {
    if (j < b || i > e) {
        return;
    }
    if (i <= b && e <= j) {
        Flip[node]++;
        push(node, b, e);
        return;
    }
    int mid = (b + e) / 2, l = 2 * node, r = 2 * node + 1;
    upd(l, b, mid, i, j);
    upd(r, mid + 1, e, i, j);
    return;
}

void solve() {
    string S; cin >> S;
    int n = S.size() + 1;
    for (int i = 1; i <= n; i++) {
        A[i] = S[i - 1];
    }

    build(1, 1, n);

    int q; cin >> q;
    while(q--) {
        char ty; cin >> ty;
        if (ty == 'I') {
            int i, j; cin >> i >> j;
            upd(1, 1, n, i, j);
        }
        else {
            int id; cin >> id;
            cout << query(1, 1, n, id) << endl;
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