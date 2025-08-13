// Created on: 2025-08-02 21:26
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn]; char S[nn], B[nn];

struct ST {
    int T[4 * nn];
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

    int query(int node, int b, int e, int i, int j) {
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
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
        B[i] = S[i];
    }

    reverse(B + 1, B + n + 1);
    map<char, deque<int>>Mp;
    for (int i = 1; i <= n; i++) {
        Mp[S[i]].push_back(i);
    }

    ll ans = 0;
    for (int i = 1, j = n, p = 1, q = n; i < j; i++, j--) { // i, j for B and p, q for A
        char curl = S[p], curr = S[q], needl = B[i], needr = B[j];
        ans += Mp[needl].front() - p - T.query(1, 1, n, p, Mp[needl].front());
        T.upd(1, 1, n, Mp[needl].front(), 1);
        ans += q - Mp[needr].back() - T.query(1, 1, n, Mp[needr].back(), q);
        T.upd(1, 1, n, Mp[needr].back(), 1);
        Mp[needl].pop_front(), Mp[needr].pop_back();
        if (Mp[curl].empty()) p++;
        if (Mp[curr].empty()) q--; 
    }

    cout << ans << endl;
    return 0;
} 