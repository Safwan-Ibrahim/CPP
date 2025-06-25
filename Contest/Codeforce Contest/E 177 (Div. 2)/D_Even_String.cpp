// Created on: 2025-04-18 00:03
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 5e5 + 8, mod = 998244353;
int n, Fact[nn], Ifact[nn], Ans[28][nn];

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

void prec() {
    Fact[0] = 1;
    for (int i = 1; i < nn; i++) {
        Fact[i] = 1LL * i * Fact[i - 1] % mod;
    }
    Ifact[nn - 1] = power(Fact[nn - 1], mod - 2, mod);
    for (int i = nn - 2; i >= 0; i--) {
        Ifact[i] = 1LL * Ifact[i + 1] * (i + 1) % mod;
    }
}

vector<int>C(26, 0);
int way(int i, int sum) {
    if (i == 27) {
        return sum == n / 2;
    }
    int &ans = Ans[i][sum];
    if (ans != -1) {
        return ans;
    }
    ans = way(i + 1, sum + C[i]);
    ans += way(i + 1, sum);
    return ans;
}

void Try() {
    n = 0; 
    for (int i = 0; i < 26; i++) {
        cin >> C[i];
        n += C[i];
    }

    memset(Ans, -1, sizeof Ans);
    

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin >> t;
    prec();
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 