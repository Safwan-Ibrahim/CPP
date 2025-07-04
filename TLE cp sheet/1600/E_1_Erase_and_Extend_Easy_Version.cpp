// Created on: 2025-05-27 20:58
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 5e5 + 18;
int n, k;
string S;

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

int lcp(int i, int j, int x, int y) { // O(log n)
    int l = 1, r = min(j - i + 1, y - x + 1), ans = 0;
    while (l <= r) {
      int mid = l + r >> 1;
      if (Hs.sub_hash(i, i + mid - 1) == Hs.sub_hash(x, x + mid - 1)) {
        ans = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    return ans;
}

int compare(int i, int j, int x, int y) { // O(log n)
    int lc = lcp(i, j, x, y);
    int len1 = j - i + 1, len2 = y - x + 1;
    if (len1 == len2 and lc == len1) return 0; //equal
    else if (lc == len1) return -1;
    else if (lc == len2) return 1;
    else return (S[i + lc] < S[x + lc] ? -1 : 1);
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    cin >> S;
    n = min(n, k);

    Hs.prec();
    Hs.calculate(S);
    int last = n;
    for (int i = 1; i < n; i++) {
        int len = min(i, n - i);
        int cmp = compare(0, len - 1, i, i + len - 1);
        if (cmp == -1 || cmp == 0 && len == n - i) {
            last = i; break;
        }
    }

    int p = 0;
    for (int i = 0; i < k; i++) {
        cout << S[p++];
        if (p == last) p = 0;
    }
    cout << endl;
    
    return 0;
} 