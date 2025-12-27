// Created on: 2025-07-15 07:03
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 27, mod = 1e9 + 7;

int Fact[nn], IFact[nn];
int power(int x, int n) {
    int ans = 1 % mod;
    while(n > 0) {
        if (n & 1) {
            ans = 1LL * ans * x % mod;
        }
        n >>= 1;
        x = 1LL * x * x % mod;
    }  
    return ans; 
}

void prec() {
    int n = nn - 5;
    Fact[0] = 1 % mod;
    for (int i = 1; i <= n; i++) {
        Fact[i] = 1LL * Fact[i - 1] * i % mod;
    }

    IFact[n] = power(Fact[n], mod - 2);
    for (int i = n - 1; i >= 0; i--) { 
        IFact[i] = 1LL * IFact[i + 1] * (i + 1) % mod;
    }
}

int nCr(int n, int r) {
    return 1LL * Fact[n] * IFact[r] % mod * IFact[n - r] % mod;
}

int nPr(int n, int r) {
    return 1LL * Fact[n] * IFact[n - r] % mod;
}

void Try() {
    int n, k; cin >> n >> k;

    if (n & 1) {
        int normal = 1;
        for (int i = 1; i <= n; i += 2) {
            normal += nCr(n, i); normal %= mod;
        }
        cout << power(normal, k) << endl;
        return ;
    }

    int normal = 0;
    for (int i = 2; i <= n; i += 2) {
        normal += nCr(n, i); normal %= mod;
    }

    int ans = power(normal, k);
    for (int i = k; i >= 1; i--) {
        int cont = 1LL * power(power(2, n), i - 1) % mod * power(normal, k - i) % mod;
        ans += cont; ans %= mod;
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t; prec();
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 