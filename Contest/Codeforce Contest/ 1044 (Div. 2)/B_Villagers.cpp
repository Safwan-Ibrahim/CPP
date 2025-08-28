// Created on: 2025-08-24 21:09
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;

    vector<int>A(n);
    for (auto &x : A) {
        cin >> x;
    }

    sort(A.rbegin(), A.rend());
    
    ll ans = 0;
    for (int i = 0; i < A.size(); i += 2) {
        ans += A[i];
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