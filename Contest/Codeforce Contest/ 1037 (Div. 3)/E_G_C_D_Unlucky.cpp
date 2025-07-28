// Created on: 2025-07-17 21:40
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int n, P[nn], S[nn]; ll A[nn];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }

    for (int i = 1; i <= n; i++) {
        A[i] = lcm(1LL * S[i], 1LL * P[i]);
    }

    ll g = 0;
    for (int i = 1; i <= n; i++) {
        g = gcd(g, A[i]);
        if (g != P[i]) {
            cout << "NO\n"; return;
        }
    }

    g = 0;
    for (int i = n; i >= 1; i--) {
        g = gcd(g, A[i]);
        if (g != S[i]) {
            cout << "NO\n"; return;
        }
    }

    cout << "YES\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 