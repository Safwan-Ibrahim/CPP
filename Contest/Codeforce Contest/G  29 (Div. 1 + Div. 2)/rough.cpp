// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, k, A[nn];

void Try() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    map<ll, int> L, R;
    for (int i = 1; i <= n; i++) {
        R[A[i]]++;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        R[A[i]]--;
        if (A[i] % k == 0) {
            ans += 1LL * R[1LL * A[i] * k] * L[A[i] / k];
        }
        L[A[i]]++;
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