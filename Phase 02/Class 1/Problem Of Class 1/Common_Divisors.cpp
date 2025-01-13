// Created on: 2025-01-02 06:04
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    ll a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll GCD = 0;
    for (int i = 1; i <= n; i++) {
        GCD = __gcd(GCD, a[i]);
    }
    
    int cnt = 0;
    for (int i = 1; 1LL * i * i <= GCD; i++) {
        if (GCD % i == 0) {
            cnt++;
            if (GCD / i != i) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
} 