// Created on: 2025-11-16 22:28
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int mod = 998244353;

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
    int n; cin >> n;
    
    vector<int> Cnt(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        Cnt[x]++;
    }

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (Cnt[i] == 1) {
            ans = 1LL * ans * 2 % mod;
        }
        else if (Cnt[i] > 1) {
            ans = 1LL * ans * Cnt[i] % mod;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (Cnt[i] > 1 && Cnt[i] <= n / 2) {
            ans += power(2, n - Cnt[i], mod) + 1;
            ans %= mod;
        }
    }

    ans--;
    if (ans < 0) ans += mod;

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