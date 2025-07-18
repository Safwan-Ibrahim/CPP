// Created on: 2025-06-11 04:39
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17, mod = 998244353; 
int pn, A[nn];
int Ans[2][nn];

int way(int i, int cnt, bool prev_liar) {
    if (i == pn + 1) return 1;
    int &ans = Ans[prev_liar][i];
    if (ans != -1) return ans;
    ans = 0;
    if (A[i] == cnt) {
        ans += way(i + 1, cnt, false); 
        if (ans >= mod) ans -= mod;
    }
    if (!prev_liar) {
        ans += way(i + 1, cnt + 1, true);
        if (ans >= mod) ans -= mod;
    }
    return ans;
}

int way_it() {
    vector<int>As_honest(pn + 1, 0);
    As_honest[0] = 1;
    for (int i = 1; i <= pn; i++) {
        if (A[i] == A[i - 1]) {
            As_honest[i] += As_honest[i - 1]; As_honest[i] %= mod;
        }
        if (i > 1 && A[i - 2] + 1 == A[i]) {
            As_honest[i] += As_honest[i - 2]; As_honest[i] %= mod;
        }
    }
    return (As_honest[pn] + As_honest[pn - 1]) % mod;
}

void Try() {
    cin >> pn;
    for (int i = 1; i <= pn; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= pn; i++) {
        Ans[0][i] = Ans[1][i] = -1;
    }
    
    cout << way(1, 0, false) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 