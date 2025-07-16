// Created on: 2025-04-30 19:52
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, k, A[nn];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    map<ll, int>L, R;
    for (int i = 1; i <= n; i++) {
        R[A[i]]++;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        R[A[i]]--;
        if (A[i] % k == 0) {
            ans += 1LL * L[A[i] / k] *  R[1LL * A[i] * k];
        }
        L[A[i]]++;
    }

    cout << ans << endl;
    return 0;
} 