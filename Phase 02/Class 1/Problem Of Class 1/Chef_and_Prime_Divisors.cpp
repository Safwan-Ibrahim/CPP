// Created on: 2025-01-03 08:55
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    ll a, b; cin >> a >> b;

    ll GCD = __gcd(a, b);
    while(GCD > 1) {
        b /= GCD;
        GCD = __gcd(a, b);
    }
    
    cout << (b == 1 ? "Yes\n" : "No\n");
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 