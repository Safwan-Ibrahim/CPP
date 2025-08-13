// Created on: 2025-01-22 22:17
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 7;
int A[nn], n;
ll T[4 * nn];

void build(int node, int b, int e) {
    if (b == e) {
        T[node] = A[b];
        return;
    }
    int l = node * 2, r = node * 2 + 1;
    int mid = (b + e) / 2;
    build(l, b, mid);
    build(r, mid + 1, e);
    T[node] = T[l] + T[r];
}

int query(int node, int b, int e, int i, int j) {
    int mid = (b + e) / 2;
    if (i >= b && j <= e) {
        return T[node];
    }
    else if (b > j || e < i) {
        return 0;
    }
    return query(node * 2, b, mid, i, j) + query(node * 2 + 1, mid + 1, e, i, j);
}

void upd(int node, int b, int e, int id, int x) {
    int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
    if (b > id || e < id) {
        return;
    }
    if (b == e && b == id) {
        T[node] = x;
        return;
    }
    upd(l, b, mid, id, x);
    upd(r, mid + 1, e, id, x);
    T[node] = T[l] + T[r];
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    build(1, 1, n);
    cout << T[1] << endl;
    upd(1, 1, n, 4, 5);
    cout << T[1] << endl;
    
    return 0;
} 