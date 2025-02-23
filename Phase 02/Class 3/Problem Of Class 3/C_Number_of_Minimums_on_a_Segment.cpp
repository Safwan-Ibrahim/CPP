// Created on: 2025-01-25 18:42
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct mp {
    int mn, cnt;
};

const int N = 1e5 + 7, inf = 1e9 + 10;
int A[N];
mp T[N * 4];

mp merge(mp l, mp r) {
    mp ans;
    ans.cnt = 0;
    ans.mn = min(l.mn, r.mn);
    if (l.mn == ans.mn) {
        ans.cnt += l.cnt;
    }
    if (r.mn == ans.mn) {
        ans.cnt += r.cnt;
    }
    return ans;
}

void build(int node, int b, int e) {
    if (b == e) {
        T[node].mn = A[b];
        T[node].cnt = 1;
        return;
    }
    int mid = (b + e) / 2, l = 2 * node, r = 2 * node + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    T[node] = merge(T[l], T[r]);
}

mp query(int node, int b, int e, int i, int j) {
    if (j < b || i > e) {
        return {inf, 0};
    }
    if (i <= b && e <= j) {
        return T[node];
    }
    int mid = (b + e) / 2, l = 2 * node, r = 2 * node + 1;
    return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}

void upd(int node, int b, int e, int id, int v) {
    if (id < b || id > e) {
        return;
    }
    if (b == e && b == id) {
        T[node].mn = v;
        T[node].cnt = 1;
        return;
    }
    int mid = (b + e) / 2, l = 2 * node, r = 2 * node + 1;
    upd(l, b, mid, id, v);
    upd(r, mid + 1, e, id, v);
    T[node] = merge(T[l], T[r]);
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    } 
    
    build(1, 1, n);

    while(q--) {
        int t, i, j; cin >> t >> i >> j;
        i++;
        if (t == 1) {
            upd(1, 1, n, i, j);
        }
        else {
            mp ans = query(1, 1, n, i, j);
            cout << ans.mn << " " << ans.cnt << endl;
        }
    }
    
    return 0;
} 