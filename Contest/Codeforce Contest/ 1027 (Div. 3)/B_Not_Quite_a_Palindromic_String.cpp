// Created on: 2025-05-26 20:45
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() { // rem k = 0;
    int n, k; cin >> n >> k;
    string S; cin >> S;
    int c0 = 0, c1 = 0;
    for (auto x : S) {
        c0 += x == '0';
        c1 += x == '1';
    }

    k *= 2;
    int ex = n - k;
    if (c0 < ex / 2 || c1 < ex / 2) {
        cout << "NO\n"; return;
    }

    c0 -= ex / 2, c1 -= ex / 2;
    if (c0 % 2 == 0 && c1 % 2 == 0) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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