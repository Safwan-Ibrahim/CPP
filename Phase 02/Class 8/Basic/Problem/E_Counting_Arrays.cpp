// Created on: 2025-11-19 12:43
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e6 + 17, mod = 1e9 + 7, mm = 2e6 + 17;
int Fact[mm], IFact[mm];

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

void prec1() {
    int n = mm - 5;
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
    if (r > n || r < 0) return 0;
    return 1LL * Fact[n] * IFact[r] % mod * IFact[n - r] % mod;
}

int Sp[nn];
map<int, int> Pf[nn], Div[nn];

void prec() {
    for (int i = 1; i < nn - 2; i++) {
        Sp[i] = i;
    }
    
    for (int i = 2; i * i < nn - 2; i++) {
        if (Sp[i] == i) {
            for (int j = i * i; j < nn - 2; j += i) {
                Sp[j] = min(Sp[j], i);
            }
        }
    }

    for (int i = 2; i < nn - 2; i++) {
        int n = i;
        while(n > 1) {
            Pf[i][Sp[n]]++;
            n /= Sp[n];
        }
    }
}

void Try() {
    int n, k; cin >> n >> k;
    
    int ans = 1;
    for (auto [x, y] : Pf[n]) {
        ans = 1LL * ans * nCr(y + k - 1, k - 1) % mod;
    }

    ans = 1LL * ans * power(2, k - 1) % mod;
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t; prec1(); prec();
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 