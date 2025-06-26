// Created on: 2025-06-26 02:02
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 5e5 + 17, mod = 998244353;
int C[26], Ans[26][nn], n;

int way(int i, int sum) {
    if (i == 26) return sum == n / 2;
    int &ans = Ans[i][sum];
    if (ans != -1) return ans;
    ans = 0;
    ans += way(i + 1, sum);
    if (C[i] && sum + C[i] <= n / 2) ans += way(i + 1, sum + C[i]);
    sum %= mod;
    return ans;
}

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
    n = 0;
    for (int i = 0; i < 26; i++) {
        cin >> C[i]; n += C[i];
    }

    for (int sum = 0; sum <= n; sum++) {
        for (int k = 0; k < 26; k++) {
            Ans[k][sum] = -1;
        }
    }
    
    int ans = 1LL * Fact[(n + 1) / 2] * Fact[n / 2] % mod;
    for (int i = 0; i < 26; i++) {
        ans = 1LL * ans * IFact[C[i]] % mod;
    }

    cout << 1LL * way(0, 0) * ans % mod << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t; prec();
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 