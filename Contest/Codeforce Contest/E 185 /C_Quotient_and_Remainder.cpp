// Created on: 2025-11-28 21:35
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try(int t) {
    ll n, k; cin >> n >> k;

    vector<ll> A(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    sort(B.rbegin(), B.rend());
    sort(A.begin(), A.end());

    int pa = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if ((B[i] + 1) * A[pa] + B[i] <= k) {
            ans++; pa++;
        }
    }

    cout << ans << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try(i);
    }
    
    return 0;
} 