// Created on: 2025-04-05 14:44
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, H[nn], A[nn];

struct ST {
    ll T[4 * nn];
    static const int inf = 1e9;
    ST() {
        memset(T, 0, sizeof T);
    }
    ll query(int node, int b, int e, int i, int j) {
        if (i <= b && j >= e) {
            return T[node];
        }
        else if (b > j || e < i) {
            return 0;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        return max(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
    }

    void upd(int node, int b, int e, int id, ll x) {
        if (b > id || e < id) {
            return;
        }
        if (b == e && b == id) {
            T[node] = max(x, T[node]);
            return;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        upd(l, b, mid, id, x);
        upd(r, mid + 1, e, id, x);
        T[node] = max(T[l], T[r]);
    }
}T;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    set<int>St;
    for (int i = 1; i <= n; i++) {
        cin >> H[i];
        St.insert(H[i]);
    }
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    map<int, int>Mp;
    int id = 0;
    for (auto x : St) {
        Mp[x] = ++id;
    }

    for (int i = 1; i <= n; i++) {
        H[i] = Mp[H[i]];
    }

    ll ans = -1;
    for (int i = 1; i <= n; i++) {
        ll mx = T.query(1, 1, id, 0, H[i]);
        mx += A[i];
        T.upd(1, 1, id, H[i], mx);
        ans = max(ans, mx);
    }    

    cout << ans << endl;

    return 0;
} 