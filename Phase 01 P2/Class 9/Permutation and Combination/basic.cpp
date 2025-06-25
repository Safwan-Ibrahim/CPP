// Created on: 2025-02-20 02:16
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e6 + 8, mod = 1e9 + 7;
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
    for (int i = n - 1; i >= 1; i--) { 
        IFact[i] = 1LL * IFact[i + 1] * (i + 1) % mod;
    }
}

int nCr(int n, int r) {
    return 1LL * Fact[n] * IFact[r] % mod * IFact[n - r] % mod;
}

int nPr(int n, int r) {
    return 1LL * Fact[n] * IFact[n - r] % mod;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    prec();
    cout << nCr(4, 2) << endl;
    
    return 0;
} 