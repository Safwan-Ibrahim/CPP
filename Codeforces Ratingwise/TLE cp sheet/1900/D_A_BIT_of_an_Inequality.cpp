// Created on: 2025-12-17 19:01
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int n, A[nn], Ro[30][nn], Lo[30][nn]; // right odd, left odd

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    for (int k = 0; k < 30; k++) {
        int cntl = 0; bool x = 0;
        for (int i = 1; i <= n; i++) {
            int cb = (A[i] >> k) & 1; // current bit
            x ^= cb;
            if (x) cntl++;
            Lo[k][i] = cntl;
        }

        int cntr = 0; x = 0;
        for (int i = n; i >= 1; i--) {
            int cb = (A[i] >> k) & 1;
            x ^= cb;
            if (x) cntr++;
            Ro[k][i] = cntr;
        }

        Ro[k][n + 1] = 0;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int k = __lg(A[i]);

        int lo = Lo[k][i - 1], ro = Ro[k][i + 1];
        int cbl = Lo[k][i] - Lo[k][i - 1], cbr = Ro[k][i] - Ro[k][i + 1]; // current bit left, right
        int le = i - lo, re = n - i + 1 - ro; // left even right even

        if (cbl) {
            swap(le, lo);
        }
        if (cbr) {
            swap(re, ro);
        }

        ans += 1LL * lo * re + 1LL * le * ro;
    }
    
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 