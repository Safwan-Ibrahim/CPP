// Created on: 2025-12-10 19:21
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n; pair<int, int> Q[nn];

struct ST {
    static const int inf = 1e9;
    vector<int> T;
    int n;

    ST(int pn) : n(pn) {
        T.assign(4 * (n + 2), -1);
    }

    int query(int node, int b, int e, int i, int j) {
        if (i <= b && j >= e) return T[node];
        if (b > j || e < i) return -1;
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        return max(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
    }

    void upd(int node, int b, int e, int id, int x) {
        if (b > id || e < id) return;
        if (b == e && b == id) {
            T[node] = max(x, T[node]);
            return;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        upd(l, b, mid, id, x);
        upd(r, mid + 1, e, id, x);
        T[node] = max(T[l], T[r]);
    }
};

void Try() {
    cin >> n;

    vector<int> Lp;
    vector<int> Rp;
    map<int, vector<int>> L;

    for (int i = 1; i <= n; i++) {
        cin >> Q[i].first >> Q[i].second;
        L[Q[i].first].push_back(Q[i].second);
        Lp.push_back(Q[i].first);
        Rp.push_back(Q[i].second);
    }

    sort(Lp.begin(), Lp.end());
    Lp.erase(unique(Lp.begin(), Lp.end()), Lp.end());

    vector<pair<int, vector<int>>> Lm;

    for (auto x : Lp) {
        Lm.push_back({x, {L[x]}});
        sort(Lm.back().second.rbegin(), Lm.back().second.rend());
    }

    sort(Rp.begin(), Rp.end());
    Rp.erase(unique(Rp.begin(), Rp.end()), Rp.end());

    int id = 0;
    map<int, int> Cp;
    for (auto x : Rp) {
        Cp[x] = ++id;
    }

    map<pair<int, int>, int> Ans;
    set<int> R;

    ST Rl(id);

    for (auto [l, v] : Lm) {
        for (auto r : v) {
            auto it = R.lower_bound(r);

            if (it != R.end()) {
                int nr = *it;
                int cp = Cp[r];
                int qv = Rl.query(1, 1, id, cp, id);
                int nl = (qv == -1 ? 1e9 : qv); 
                Ans[{l, r}] = max(0, l - nl) + max(0, nr - r);
            }

            R.insert(r);
            Rl.upd(1, 1, id, Cp[r], l);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << Ans[{Q[i].first, Q[i].second}] << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }

    return 0;
} 