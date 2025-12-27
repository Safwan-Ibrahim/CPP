// Created on: 2025-11-13 11:33
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn]; ll Ps[nn];

struct ST {
    static const ll inf = 1e18;
    vector<ll> T;
    int n;

    ST(int pn) : n(pn) {
        T.assign(4 * (n + 2), 1e18);
    }

    void build(int node, int b, int e) {
        if (b == e) {
            T[node] = Ps[b];
            return;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        T[node] = min(T[l], T[r]);
    }

    ll query(int node, int b, int e, int i, int j) {
        if (i <= b && j >= e) return T[node];
        if (b > j || e < i) return inf;
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        return min(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
    }
};

bool pos() {

    ll ps = 0;
    int mx = -2e9, id = 0;
    vector<pair<int, int>> V;
    stack<int> St;

    for (int i = 1; i <= n; i++) {
        Ps[i] = ps += A[i];

        while (!St.empty() && A[St.top()] <= A[i]) St.pop();
        int l = (St.empty() ? 0 : St.top());
        V.push_back({l, i});
        St.push(i);
    }

    ST Tmn(n); Tmn.build(1, 0, n - 1);

    for (auto [l, r] : V) {
        if (A[r] <= 0) continue;
        ll sum = Ps[r] - Tmn.query(1, 0, n - 1, l, r - 1);
        if (sum > A[r]) return true;
    }

    return false;
}

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    bool no = pos();
    reverse(A + 1, A + n + 1);
    no |= pos();

    cout << (no ? "NO\n" : "YES\n");
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 