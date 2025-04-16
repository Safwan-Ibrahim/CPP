// Created on: 2025-04-08 11:10
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e6 + 8, m1 = 1e9 + 7, m2 = 1e9 + 9, p1 = 97, p2 = 37;
int Ipow1[nn], Ipow2[nn], Pow1[nn], Pow2[nn], Pref1[nn], Pref2[nn];

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
    Pow1[0] = 1;
    Pow2[0] = 1;
    for (int i = 1; i < nn; i++) {
        Pow1[i] = 1LL * p1 * Pow1[i - 1] % m1;
        Pow2[i] = 1LL * p2 * Pow2[i - 1] % m2;
    }

    int ip1 = power(p1, m1 - 2, m1);
    int ip2 = power(p2, m2 - 2, m2);
    Ipow1[0] = Ipow2[0] = 1;
    for (int i = 1; i < nn; i++) {
        Ipow1[i] = 1LL * Ipow1[i - 1] * ip1 % m1;
        Ipow2[i] = 1LL * Ipow2[i - 1] * ip2 % m2;
    }
}

void calculate(string &S) {
    int n = S.size();
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum1 += 1LL * Pow1[i] * (S[i] - 'a' + 1) % m1;
        sum1 %= m1;
        Pref1[i] = sum1;
        sum2 += 1LL * Pow2[i] * (S[i] - 'a' + 1) % m2;
        sum2 %= m2;
        Pref2[i] = sum2;
    }
}

pair<int, int> sub_hash(int l, int r) {
    int hs1 = (Pref1[r] - (l ? Pref1[l - 1] : 0) + m1) % m1; 
    hs1 = 1LL * hs1 * Ipow1[l] % m1;
    int hs2 = (Pref2[r] - (l ? Pref2[l - 1] : 0) + m2) % m2; 
    hs2 = 1LL * hs2 * Ipow2[l] % m2;
    return {hs1, hs2};
}

pair<int, int> get_hash(string &S) {
    int n = S.size();
    int hs1 = 0, hs2 = 0;
    for (int i = 0; i < n; i++) {
        hs1 += 1LL * (S[i] - 'a' + 1) * Pow1[i] % m1;
        hs1 %= m1;
        hs2 += 1LL * (S[i] - 'a' + 1) * Pow2[i] % m2;
        hs2 %= m2;
    }
    return {hs1, hs2};
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    string S, T; cin >> S >> T;
    prec();
    calculate(S);
    int n = S.size(), m = T.size();
    int ans = 0;
    auto hs_t = get_hash(T);
    for (int i = 0; i + m - 1 < n; i++) {
        auto hs_c = sub_hash(i, i + m - 1);
        ans += hs_c == hs_t;
    }

    cout << ans << endl;
    
    return 0;
} 