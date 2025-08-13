// Created on: 2025-08-02 19:39
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e6 + 17;
int n, A[nn], B[nn];

struct ST {
    ll T[4 * nn];
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
        T[node] = T[l] + T[r];
    }

    ll query(int node, int b, int e, int i, int j) {
        if (i <= b && j >= e) {
            return T[node];
        }
        else if (b > j || e < i) {
            return 0;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
    }

    void upd(int node, int b, int e, int id, int x) {
        if (b > id || e < id) {
            return;
        }
        if (b == e && b == id) {
            T[node] += x;
            return;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        upd(l, b, mid, id, x);
        upd(r, mid + 1, e, id, x);
        T[node] = T[l] + T[r];
    }
}T;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    vector<int>V;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        V.push_back(A[i]);
    }

    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    map<int, int>Mp; int id = 0;
    for (auto x : V) {
        Mp[x] = ++id;
    }

    for (int i = 1; i <= n; i++) {
        A[i] = Mp[A[i]];
    }
    
    for (int i = n; i >= 1; i--) {
        B[i] = T.query(1, 1, id, 1, A[i] - 1);
        T.upd(1, 1, id, A[i], 1);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        T.upd(1, 1, id, A[i], -1);
    }

    for (int i = n; i >= 1; i--) {
        ans += T.query(1, 1, id, 0, A[i]);
        T.upd(1, 1, id, A[i], B[i]);
    }

    cout << ans << endl;
    
    return 0;
} 