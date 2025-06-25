// Created on: 2025-05-19 21:36
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, A[nn];

bool ok(int k) {
    int gcd_ = 0;
    for (int i = k + 1; i <= n; i++) {
        gcd_ = gcd(abs(A[i] - A[i - k]), gcd_);
    }
    return gcd_ != 1;
}

void Try() {
    cin >> n; 
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    int ans = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans += ok(i);
            if (i != n / i) ans += ok(n / i);
        }
    }

    cout << ans << endl;
    return;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 