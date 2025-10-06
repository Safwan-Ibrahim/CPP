// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int mod = 1e9 + 7;

int power(int x, int n, int m) {
    int ans = 1 % m;
    while(n > 0) {
        if (n & 1) {
            ans = 1LL * ans * x % m;
        }
        n >>= 1;
        x = 1LL * x * x % m;
    }
    return ans;
}

int mod_inv(int x, int mod) {
    return power(x, mod - 2, mod);
}

int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r > n - r) r = n - r; 

    int res = 1;
    for (int i = 0; i < r; i++) {
        res = 1LL * res * (n - i) % mod;
        res = 1LL * res * mod_inv(i + 1, mod) % mod;
    }
    return res;
}

void Try() {
    int a, b, k; cin >> a >> b >> k;
    
    int n = (1LL * (a - 1) * k + 1) % mod;
    int m = (1LL * nCr(n, a) * k % mod * (b - 1) + 1) % mod;

    cout << n << " " << m << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 