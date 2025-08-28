// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
ll n, A[nn];

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    ll ans = max(0LL, A[1] - A[2]);
    A[1] = min(A[1], A[2]);
    for (int i = 3; i <= n; i += 2) {
        if (A[i] + A[i - 2] > A[i - 1]) {
            ans += A[i] + A[i - 2] - A[i - 1];
            A[i] -= A[i] + A[i - 2] - A[i - 1];
        } 
        if (i + 1 <= n && A[i] > A[i + 1]) ans += A[i] - A[i + 1], A[i] = A[i + 1]; 
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