// Created on: 2025-05-29 21:37
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e3 + 8, mod = 1e9 + 7;
int n, k, A[nn];

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
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    sort(A + 1, A + n + 1);
    
    int p = n - k + 1;
    int l = p, r = p;
    while(r <= n && A[r] == A[p]) {
        r++;
    }
    while(l >= 1 && A[l] == A[p]) {
        l--;
    }
    r--, l++;

    int total = r - l + 1, select = r - p + 1;
    cout << nCr(total, select) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t; prec();
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 