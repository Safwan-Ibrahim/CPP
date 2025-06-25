// Created on: 2025-05-22 12:59
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8, mod = 998244353;
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

void Try() {
    int n; cin >> n; n /= 3;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        vector<int>V(3, 0);
        cin >> V[0] >> V[1] >> V[2];
        int mn = *min_element(V.begin(), V.end());
        int cnt = count(V.begin(), V.end(), mn);
        ans = 1LL * ans * cnt % mod;
    }

    ans = 1LL * ans * nCr(n, n / 2) % mod;
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; prec();
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 