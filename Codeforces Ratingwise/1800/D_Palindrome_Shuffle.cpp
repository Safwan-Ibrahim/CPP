// Created on: 2025-12-02 19:01
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
array<int, 27> P[nn];
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

};

string_hash H1, H2;

bool is_pali(int l, int r, int x, int y) {
    if (r < l || y < x) return true;
    auto sh1 = H1.sub_hash(l, r);
    auto sh2 = H2.sub_hash(n - y - 1, n - x - 1);
    return sh1 == sh2;
}

array<int, 27> get_char(int i, int j) {
    if (i == 0) return P[j];
    array<int, 27> ans;
    for (int k = 0; k < 27; k++) {
        ans[k] = P[j][k] - P[i - 1][k];
    }
    return ans;
}

bool pos_pali(array<int, 27> sum) {
    int oc = 0;

    for (auto x : sum) {
        oc += x & 1;
    }

    return oc < 2;
}

bool ok(int x) {

    for (int ep = x - 1, sp = 0; ep < n; ep++, sp++) {
        bool pos = 1;

        int ln = min(sp, n - ep - 1);
        pos &= is_pali(0, ln - 1, n - 1 - ln + 1, n - 1);

        int esp = 0, eep = -1;

        if (sp < n - ep - 1) esp = ep + 1, eep = n - 1 - ln + 1 - 1;
        else if (sp > n - ep - 1) esp = ln - 1 + 1, eep = sp - 1;

        if (esp > eep) {
            pos &= pos_pali(get_char(sp, ep));
            if (pos) {
                return 1;
            }
            else continue;
        }
        
        int ex = eep - esp + 1;
        
        if (ex <= x) {
            auto change = get_char(sp, ep);
            auto extra = get_char(esp, eep);
            
            for (int i = 0; i < 27; i++) {
                if (extra[i] > change[i]) pos = 0;
                change[i] -= extra[i];
            }
            
            pos &= pos_pali(change);
        }
        else {
            auto change = get_char(sp, ep);
            auto extra = get_char(n - ep - 1, n - sp - 1);
            
            for (int i = 0; i < 27; i++) {
                if (extra[i] > change[i]) pos = 0;
                change[i] -= extra[i];
            }
            
            pos &= pos_pali(change);
            
            int i, j;
            if (esp < ep) {
                i = n - sp - 1 + 1, j = sp - 1;
            }            
            else {
                i = ep + 1, j = n - ep - 1 - 1;
            }
            
            pos &= is_pali(i, j, i, j);
        }
        
        if (pos) return 1;
    }

    return false;
}

void Try() {
    string S, T; cin >> S;
    T = {S.rbegin(), S.rend()};
    
    n = S.size();
    H1.calculate(S);
    H2.calculate(T);

    array<int, 27> sum;
    for (int i = 0; i < 27; i++) {
        sum[i] = 0;
    }

    for (int i = 0; i < S.size(); i++) {
        sum[S[i] - 'a']++;
        P[i] = sum;
    }


    int lo = 1, hi = S.size() - 1, ans = n;
    while (lo <= hi) {
        int mid = lo + hi >> 1;

        if (ok(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    if (is_pali(0, n - 1, 0, n - 1)) ans = 0;

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    H1.prec(); H2.prec();
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 