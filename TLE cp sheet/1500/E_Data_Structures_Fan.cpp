// Created on: 2025-05-06 08:06
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 18;
int n, A[nn], X[nn];
char S[nn];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }

    int x = 0, x0 = 0, x1 = 0;
    for (int i = 1; i <= n; i++) {
        x ^= A[i];
        X[i] = x;
        if (S[i] == '1') {
            x1 ^= A[i];
        }
        else {
            x0 ^= A[i];
        }
    }

    int q; cin >> q;
    while(q--) {
        int ty; cin >> ty;
        if (ty == 1) {
            int l, r; cin >> l >> r;
            int x = X[r] ^ X[l - 1];
            x0 ^= x;
            x1 ^= x;
        }
        else {
            int c; cin >> c;
            cout << (c == 0 ? x0 : x1) << " ";
        }
    }
    cout << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 