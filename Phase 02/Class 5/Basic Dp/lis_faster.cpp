// Created on: 2025-03-23 01:31
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 8;
int n, A[N];
int T[4 * N];

void build(int node, int b, int e) {
    if (b == e) {
        T[node] = A[b]; return;
    }
    int l = 2 * node, r = 2 * node + 1, mid = (b + e) / 2;
    build(l, b, mid);
    build(r, mid + 1, e);
    T[node] = max(T[l], T[r]);
}

void upd(int node, int b, int e, int id, int v) {
    if (id > e || id < b) {
        return;
    }
    if (b == id && id == e) {
        T[node] = max(T[node], v); return;
    }
    int l = 2 * node, r = 2 * node + 1, mid = (b + e) / 2;
    upd(l, b, mid, id, v);
    upd(r, mid + 1, e, id, v);
    T[node] = max(T[l], T[r]);
}

int query(int node, int b, int e, int i, int j) {
    if (e < i || j < b) {
        return 0;
    }
    if (b >= i && e <= j) {
        return T[node];
    }
    int l = 2 * node, r = 2 * node + 1, mid = (b + e) / 2;
    return max(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n;
    set<int>St;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        St.insert(A[i]);
    }

    map<int, int>Mp, Mp2;
    int id = 0;
    for (auto x : St) {
        Mp[x] = ++id;
    }

    for (int i = 1; i <= n; i++) {
        A[i] = Mp[A[i]];
        cerr << A[i] << " ";
    }

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int mx = 0;
        mx = max(mx, query(1, 1, n, 1, A[i] - 1));
        mx++;
        upd(1, 1, n, A[i], mx);
        ans = max(ans, mx);
    }

    cout << ans << endl;

    return 0;
} 