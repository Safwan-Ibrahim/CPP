// Created on: 2025-03-16 20:50
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, a, b; cin >> n >> a >> b; 
    for (ll i = 1; i <= n; i *= a) {
        if ((n - i) % b == 0) {
            cout << "YES\n"; return;
        }
        if (a == 1) {
            break;
        }
    }
    cout << "NO\n";

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 