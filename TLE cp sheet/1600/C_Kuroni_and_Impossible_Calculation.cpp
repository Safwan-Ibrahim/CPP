// Created on: 2025-06-03 05:38
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 18;
int n, mod, A[nn];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> mod;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    if (n > 1020) {
        cout << 0 << endl; return 0;
    }

    int ans = 1 % mod;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans *= abs(A[i] - A[j]) % mod;
            ans %= mod;
        }
    }

    cout << ans << endl;
    
    return 0;
} 