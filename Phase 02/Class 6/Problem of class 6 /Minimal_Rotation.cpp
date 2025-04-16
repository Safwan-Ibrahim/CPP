// Created on: 2025-04-14 23:57
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e6 + 8;
string S;
int n;

struct string_hash {
    static const int m0 = 127657753, m1 = 987654319;
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

int lcp(pair<int, int>a, pair<int, int>b) {
    int lo = 1, hi = n, ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        auto p1 = Hs.sub_hash(a.first, a.first + mid - 1);
        auto p2 = Hs.sub_hash(b.first, b.first + mid - 1);
        if (p1 != p2) {
            hi = mid - 1;
        }
        else {
            ans = mid;
            lo = mid + 1;
        }
    }
    return ans;
}

bool cmp(pair<int, int>a, pair<int, int>b, int lci) {
    if (a.second - a.first + 1 == lci) {
        return true;
    }
    if (S[a.first + lci] < S[b.first + lci]) {
        return true;
    }
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> S;
    n = S.size();
    S += S;
    Hs.prec();
    Hs.calculate(S);

    pair<int, int>a = {0, n - 1};
    for (int i = 0; i + n - 1 < S.size(); i++) {
        int s = lcp({a}, {i, i + n - 1});
        if (!cmp({a}, {i, i + n - 1}, s)) {
            a = {i, i + n - 1};
        }
    }

    cout << S.substr(a.first, n) << endl;
    
    return 0;
} 