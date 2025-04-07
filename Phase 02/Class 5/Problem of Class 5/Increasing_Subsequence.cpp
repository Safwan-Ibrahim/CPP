// Created on: 2025-03-28 21:41
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 8;
int n, A[N];

struct ST {
    int T[4 * N];
    static const int inf = 1e9;
    ST() {
        memset(T, 0, sizeof T);
    }

    int query(int node, int b, int e, int i, int j) {
        if (i <= b && j >= e) {
            return T[node];
        }
        else if (b > j || e < i) {
            return 0;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        return max(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
    }

    void upd(int node, int b, int e, int id, int x) {
        if (b > id || e < id) {
            return;
        }
        if (b == e && b == id) {
            T[node] = max(T[node], x);
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
        cin >> A[i];
        St.insert(A[i]);
    }

    map<int, int>Mp;
    int id = 0;
    for (auto x : St) {
        Mp[x] = ++id;
    }

    for (int i = 1; i <= n; i++) {
        A[i] = Mp[A[i]];
    }

    int mx = 1;
    for (int i = 1; i <= n; i++) {
        int ans = T.query(1, 1, n, 1, A[i] - 1);
        ans++;
        mx = max(mx, ans);
        T.upd(1, 1, n, A[i], ans);
    }

    cout << mx << endl;
    
    return 0;
} 