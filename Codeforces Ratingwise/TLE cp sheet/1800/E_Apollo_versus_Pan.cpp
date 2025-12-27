// Created on: 2025-11-19 18:33
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 5e5 + 17, mod = 1e9 + 7;
int n; ll A[nn];

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

void Try() {
    cin >> n;

    vector<int> Cnt(62, 0);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x; sum += x;
        sum %= mod;
        for (int k = 0; k < 60; k++) {
            Cnt[k] += x >> k & 1;
        }
        A[i] = x;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int Soi = sum, Sai = sum;

        for (int k = 0; k < 60; k++) {
            if (A[i] >> k & 1) {
                Soi += 1LL * power(2, k, mod) * (n - Cnt[k]) % mod; Soi %= mod;
            }
            else {
                Sai -= 1LL * power(2, k, mod) * Cnt[k] % mod; Sai %= mod;
                Sai += mod; Sai %= mod;
            }
        }

        ans += 1LL * Soi * Sai % mod;
        ans %= mod;
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