// Created on: 2025-04-13 17:44
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 3e5 + 8;

struct string_hash {
    static const int m0 = 1000000363, m1 = 1000000403;
    static const int p0 = 79, p1 = 97;
    int Pref[2][nn], Pow[2][nn], Ipow[2][nn];

    int power(int x, int n, int mod) {
        int ans = 1 % mod;
        while (n > 0) {
            if (n & 1) ans = 1LL * ans * x % mod;
            x = 1LL * x * x % mod;
            n >>= 1;
        }
        return ans;
    }

    void prec() {
        Pow[0][0] = Pow[1][0] = 1;
        for (int i = 1; i < nn; i++) {
            Pow[0][i] = 1LL * Pow[0][i - 1] * p0 % m0;
            Pow[1][i] = 1LL * Pow[1][i - 1] * p1 % m1;
        }

        int ip0 = power(p0, m0 - 2, m0);
        int ip1 = power(p1, m1 - 2, m1);
        Ipow[0][0] = Ipow[1][0] = 1;

        for (int i = 1; i < nn; i++) {
            Ipow[0][i] = 1LL * Ipow[0][i - 1] * ip0 % m0;
            Ipow[1][i] = 1LL * Ipow[1][i - 1] * ip1 % m1;
        }
    }

    void calculate(const string& S) {
        int n = S.size();
        int sum0 = 0, sum1 = 0;

        for (int i = 0; i < n; i++) {
            sum0 = (sum0 + 1LL * Pow[0][i] * (S[i] - 'a' + 6)) % m0;
            Pref[0][i] = sum0;

            sum1 = (sum1 + 1LL * Pow[1][i] * (S[i] - 'a' + 5)) % m1;
            Pref[1][i] = sum1;
        }
    }

    pair<int, int> sub_hash(int l, int r) {
        int h0 = (Pref[0][r] - (l ? Pref[0][l - 1] : 0) + m0) % m0;
        h0 = 1LL * h0 * Ipow[0][l] % m0;

        int h1 = (Pref[1][r] - (l ? Pref[1][l - 1] : 0) + m1) % m1;
        h1 = 1LL * h1 * Ipow[1][l] % m1;

        return {h0, h1};
    }

    pair<int, int> get_hash(const string& S) {
        int n = S.size();
        int h0 = 0, h1 = 0;

        for (int i = 0; i < n; i++) {
            h0 = (h0 + 1LL * (S[i] - 'a' + 6) * Pow[0][i]) % m0;
            h1 = (h1 + 1LL * (S[i] - 'a' + 5) * Pow[1][i]) % m1;
        }

        return {h0, h1};
    }
}Hs;

void Try() {
    int n, k; cin >> n >> k;
    string S; cin >> S;
    Hs.calculate(S);
    set<pair<int, int>>St;
    for (int i = 0; i + k - 1 < n; i++) {
        St.insert(Hs.sub_hash(i, i + k - 1));
    }
    cout << St.size() << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    Hs.prec();
    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 