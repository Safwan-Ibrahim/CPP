// Created on: 2025-01-13 19:06
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;

    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int mx = -1;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, a[i]);
    }

    int GCD = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != mx) {
            GCD = gcd(mx - a[i], GCD);
            sum += mx - a[i];
        }
    }

    cout << sum / GCD << " " << GCD << endl;
    return 0;
} 