// Created on: 2025-05-16 08:30
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    vector<pair<int, int>>A(n), Store(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        A[i] = Store[i] = {x, y};
    }
    
    sort(A.begin(), A.end());
    bool yes = false; int mx = A.front().first;
    for (auto [l, r] : A) {
        if (mx < l) {
            yes = true; break;
        }
        mx = max(mx, r);
    }

    if (!yes) {
        cout << -1 << endl; return;
    }

    for (auto [l, r] : Store) {
        cout << (r <= mx ? 1 : 2) << " ";
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