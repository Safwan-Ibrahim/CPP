// Created on: 2025-05-11 20:41
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, m, p, q; cin >> n >> m >> p >> q;
    if (p == 1) {
        if (q % p == 0 && (q / p) * n == m) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    else {
        if (n % p == 0) {
            if (n / p * q == m) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else {
            cout << "YES\n";
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 