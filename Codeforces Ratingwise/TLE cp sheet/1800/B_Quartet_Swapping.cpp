// Created on: 2025-11-27 17:49
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n;

struct ST {
    static const int inf = 1e9;
    vector<int> T;
    int n;

    ST(int pn) : n(pn) {
        T.assign(4 * (n + 2), 0);
    }

    int query(int node, int b, int e, int i, int j) {
        if (i <= b && j >= e) return T[node];
        if (b > j || e < i) return 0;
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
    }

    void upd(int node, int b, int e, int id, int x) {
        if (b > id || e < id) return;
        if (b == e && b == id) {
            T[node] += x;
            return;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        upd(l, b, mid, id, x);
        upd(r, mid + 1, e, id, x);
        T[node] = T[l] + T[r];
    }
};

bool parity(vector<int> &A) {
    vector<int> O(n + 1, -1);
    for (int i = 0; i < A.size(); i++) {
        O[A[i]] = i;
    }

    int m = A.size() + 1;
    ST T(m);

    int id = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        if (O[i] == -1) continue;
        int need = O[i] - id + T.query(1, 0, m, O[i], m);
        T.upd(1, 0, m, O[i], 1);
        id++;
        sum += need;
    }

    return sum & 1;
}

void Try() {
    cin >> n;

    vector<int> O, E;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (i & 1) O.push_back(x);
        else E.push_back(x);
    }
    
    bool change = parity(E) ^ parity(O);
    sort(E.begin(), E.end());
    sort(O.begin(), O.end());

    if (change) {
        if (!(n & 1)) swap(E[E.size() - 1], E[E.size() - 2]);
        else swap(O[O.size() - 1], O[O.size() - 2]);
    }

    int po = 0, pe = 0;
    for (int i = 1; i <= n; i++) {
        if (i & 1) cout << O[po++] << " ";
        else cout << E[pe++] << " ";
    }

    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 