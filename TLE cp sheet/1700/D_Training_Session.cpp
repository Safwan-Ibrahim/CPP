// Created on: 2025-07-15 03:46
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn], B[nn], Ca[nn], Cb[nn];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i] >> B[i];
        Ca[A[i]]++, Cb[B[i]]++;
    }

    ll ans = 1LL * n * (n - 1) * (n - 2) / 6;
    for (int i = 1; i <= n; i++) {
        ans -= 1LL * (Ca[A[i]] - 1) * (Cb[B[i]] - 1);
    }

    cout << ans << endl;
    
    for (int i = 1; i <= n; i++) {
        Ca[A[i]] = Cb[B[i]] = 0;
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