// Created on: 2025-04-13 16:28
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1508;
string S;
bool Mp[27];

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

struct ST {
    int T[4 * nn];
    static const int inf = 1e9;
    // ST() {
    //     memset(T, 0, sizeof T);
    // }
    void build(int node, int b, int e) {
        if (b == e) {
            T[node] = Mp[S[b] - 'a'];
            return;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        T[node] = T[l] + T[r];
    }

    int query(int node, int b, int e, int i, int j) {
        if (i <= b && j >= e) {
            return T[node];
        }
        else if (b > j || e < i) {
            return 0;
        }
        int mid = (b + e) / 2, l = node * 2, r = node * 2 + 1;
        return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
    }

}T;

struct string_hash {
    static const int m0 = 1e9 + 7, m1 = 1e9 + 9;
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

    ll sub_hash(int l, int r) {
        int h0 = (Pref[0][r] - (l ? Pref[0][l - 1] : 0) + m0) % m0;
        h0 = 1LL * h0 * Ipow[0][l] % m0;

        int h1 = (Pref[1][r] - (l ? Pref[1][l - 1] : 0) + m1) % m1;
        h1 = 1LL * h1 * Ipow[1][l] % m1;

        return 1LL * h0 * 1e9 + h1;
    }

    ll get_hash(const string& S) {
        int n = S.size();
        int h0 = 0, h1 = 0;

        for (int i = 0; i < n; i++) {
            h0 = (h0 + 1LL * (S[i] - 'a' + 6) * Pow[0][i]) % m0;
            h1 = (h1 + 1LL * (S[i] - 'a' + 5) * Pow[1][i]) % m1;
        }

        return 1LL * h0 * 1e9 + h1;
    }
}Hs;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> S;
    for (int i = 0; i < 26; i++) {
        char c; cin >> c;
        Mp[i] = c == '0';
    }
    int k; cin >> k;

    Hs.prec();
    Hs.calculate(S);

    gp_hash_table<ll, int>St;
    T.build(1, 0, S.size() - 1);
    for (int i = 0; i < S.size(); i++) {
        for (int j = i; j < S.size(); j++) {
            if (T.query(1, 0, S.size() - 1, i, j) <= k) {
                St[Hs.sub_hash(i, j)]++;
            }
        }
    }

    cout << St.size() << endl;
    
    return 0;
} 