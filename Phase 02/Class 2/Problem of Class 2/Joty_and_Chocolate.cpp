// Created on: 2025-01-13 15:13
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, a, b, p, q; cin >> n >> a >> b >> p >> q;

    ll LCM = 1LL * a * b / gcd(a, b);
    ll ans = 1LL * (n / a) * p + 1LL * (n / b) * q - min(p, q) * (n / LCM);

    cout << ans << endl; 
    return 0;
} 