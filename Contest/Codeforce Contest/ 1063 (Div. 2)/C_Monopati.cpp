// Created on: 2025-11-10 21:59
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 4e5 + 17;
int n, A[2][nn];

struct ST {
    int n;
    vector<int> T;

    ST(int pn) : n(pn) {
        T.assign(4 * (n + 5), 1e9);
    }

    int query(int node, int b, int e, int i, int j) {
        if (i <= b && j >= e) return T[node];
        if (b > j || e < i) return 1e9;
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        return min(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
    }

    void upd(int node, int b, int e, int id, int x) {
        if (b > id || e < id) return;
        if (b == e && b == id) {
            T[node] = min(x, T[node]);
            return;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        upd(l, b, mid, id, x);
        upd(r, mid + 1, e, id, x);
        T[node] = min(T[l], T[r]);
    }
};

void Try() {
    cin >> n;

    for (int j = 0; j < 2; j++) {
        for (int i = 1; i <= n; i++) {
            cin >> A[j][i];
        }
    }

    vector<int> Pmx(n + 1), Pmn(n + 1), Smx(n + 1), Smn(n + 1);

    int pmx = -1, pmn = 1e9;
    for (int i = 1; i <= n; i++) {
        pmx = max(pmx, A[0][i]);
        pmn = min(pmn, A[0][i]);
        Pmx[i] = pmx;
        Pmn[i] = pmn;
    }

    int smx = -1, smn = 1e9;
    for (int i = n; i >= 1; i--) {
        smx = max(smx, A[1][i]);
        smn = min(smn, A[1][i]);
        Smx[i] = smx;
        Smn[i] = smn;
    }

    int m = 2 * n + 5;
    ST T(m);

    for (int i = 1; i <= n; i++) {
        int mn = min(Pmn[i], Smn[i]);
        int mx = max(Pmx[i], Smx[i]);
        T.upd(1, 1, m, mn, mx);
    }

    ll ans = 0;
    for (int i = 1; i <= 2 * n; i++) {
        int need = T.query(1, 1, m, i, m);
        if (need >= 1e9) break;
        ans += 2 * n - need + 1;
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 