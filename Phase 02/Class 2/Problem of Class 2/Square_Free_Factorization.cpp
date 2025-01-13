// Created on: 2025-01-08 02:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int max_prime_power(int n) {
    int mx = 1;
    for (int i = 2; i * i <= n; i++) {
        int p = 0;
        while(n % i == 0) {
            p++;
            n /= i;
        }
        mx = max(p, mx);
    }
    return mx;
}

void solve() {
    int n; cin >> n;

    cout << max_prime_power(n) << endl; 
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 