// Created on: 2025-02-02 02:06
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    vector<int>A(3);
    int m; cin >> A[0] >> A[1] >> A[2] >> m;

    sort(A.begin(), A.end());
    if (A[2] - 1 - (A[0] + A[1]) <= m && m <= A[0] + A[1] + A[2] - 3) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 