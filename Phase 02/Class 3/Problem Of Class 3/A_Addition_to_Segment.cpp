// Created on: 2025-01-27 22:43
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 9;
ll Lazy[N * 4];
ll T[N * 4];

// void build(int node, int b, int e) {
//     if (b == e) {
//         T[node] = A[b];
//     }
//     int mid = (b + e) / 2, l = 2 * node, r = 2 * node + 1;
//     build(l, b, mid);
//     build(r, mid + 1, e);
//     T[node] = T[l] + T[r];
// }

void push(int node, int b, int e) {
    if (Lazy[node] == 0) {
        return;
    }
    T[node] += (e - b + 1) * Lazy[node];
    if (b != e) {
        int l = 2 * node, r = 2 * node + 1;
        Lazy[l] += Lazy[node];
        Lazy[r] += Lazy[node]; 
    }
    Lazy[node] = 0;
}

void upd(int node, int b, int e, int i, int j, int x) {
    push(node, b, e);
    if (j < b || e < i) {
        return;
    }
    if (i <= b && e <= j) {
        Lazy[node] = x;
        push(node, b, e);
        return;
    }
    int mid = (b + e) / 2, l = 2 * node, r = 2 * node + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    T[node] = T[l] + T[r];
}

ll query(int node, int b, int e, int i, int j) {
    push(node, b, e);
    if (j < b || i > e) {
        return 0;
    }
    if (i <= b && e <= j) {
        return T[node];
    }
    int mid = (b + e) / 2, l = 2 * node, r = 2 * node + 1;
    return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n, m; cin >> n >> m;
    
    while(m--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r, v; cin >> l >> r >> v;
            l++;
            upd(1, 1, n, l, r, v);
        }
        else {
            int id; cin >> id;
            id++;
            cout << query(1, 1, n, id, id) << endl;
        }
    }

    return 0;
} 