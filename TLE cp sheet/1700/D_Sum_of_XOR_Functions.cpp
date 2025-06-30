// Created on: 2025-06-30 18:38
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 3e5 + 17, mod = 998244353;
int n, A[nn];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    int ans = 0;
    for (int k = 0; k < 30; k++) {
        int odd_cnt = 0, even_cnt = 1, total_odd = 0, total_even = 0, x = 0;
        for (int i = 1; i <= n; i++) {
            int b = x ^ (A[i] >> k & 1);
            if (b) {
                ans += 1LL * (1 << k) * ((1LL * even_cnt * i - total_even) % mod) % mod; ans %= mod;
            }
            else {
                ans += 1LL * (1 << k) * ((1LL * odd_cnt * i - total_odd) % mod) % mod; ans %= mod;
            }
            x ^= (A[i] >> k & 1);
            if (x & 1) {
                odd_cnt++;
                total_odd += i; total_odd %= mod;
            }
            else {
                even_cnt++;
                total_even += i; total_even  %= mod;
            }
        }
    }

    cout << ans << endl;
    return 0;
} 