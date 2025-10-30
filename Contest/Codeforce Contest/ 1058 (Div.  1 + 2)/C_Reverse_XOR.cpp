// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;

    while (n && n % 2 == 0) n >>= 1;
    
    int i = 0, j = __lg(n);
    while (i < j) {
        int a = (n >> i) & 1;
        int b = (n >> j) & 1;
        if (a != b) {
            cout << "NO\n"; return;
        }
        i++, j--;
    }

    if (i == j && ((n >> i) & 1)) {
        cout << "NO\n"; return;
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