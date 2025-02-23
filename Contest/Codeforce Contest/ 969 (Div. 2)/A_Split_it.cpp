// Created on: 2025-02-18 14:17
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, k; cin >> n >> k;
    string S; cin >> S;

    if (n == k * 2) {
        cout << "NO\n"; return;
    }

    if (!k) {
        cout << "YES\n"; return;
    }

    for (int i = 0, j = n - 1; i < k; i++,j--) {
        if (S[i] != S[j]) {
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