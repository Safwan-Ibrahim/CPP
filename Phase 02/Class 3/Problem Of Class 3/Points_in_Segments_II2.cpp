// Created on: 2025-01-26 10:36
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 5e4;
int L[nn], R[nn], Q[nn], Ans[nn * 3];

void solve() {
    int n, q; cin >> n >> q;

    vector<int>Points;
    for (int i = 1; i <= n; i++) {
        cin >> L[i] >> R[i];
        Points.push_back(L[i]);
        Points.push_back(R[i]);
    }

    for (int i = 1; i <= q; i++) {
        cin >> Q[i];
        Points.push_back(Q[i]);
    }

    sort(Points.begin(), Points.end());
    Points.erase(unique(Points.begin(), Points.end()), Points.end());

    map<int, int>MP;
    int id = 0;
    for (auto x : Points) {
        MP[x] = ++id;
    }

    for (int i = 1; i <= n; i++) {
        L[i] = MP[L[i]];
        R[i] = MP[R[i]];
    }

    for (int i = 1; i <= q; i++) {
        Q[i] = MP[Q[i]];
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    
    return 0;
} 