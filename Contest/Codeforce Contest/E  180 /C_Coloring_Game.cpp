// Created on: 2025-06-23 21:46
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 5e3 + 7;
int n, A[nn];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    ll ans = 0;
    for (int i = 1; i + 2 <= n; i++) {
        for (int j = i + 1; j + 1 <= n; j++) {
            int mx_ = (A[i] + A[j]);
            int mn = max(0, A[n] - A[i] - A[j]);
            ans += max(0, (int) (lower_bound(A + j + 1, A + n + 1, mx_) - upper_bound(A + j + 1, A + n + 1, mn)));
        }
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