// Created on: 2025-06-23 13:23
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;

    for (int i = 1; i < n; i++) {
        if (i == n - 2) continue;
        cout << 1 << " " << i << endl;
        if (i == 2 && n % 2 == 1 || i == 3 && n % 2 == 0) {
            cout << n << " " << i << endl;
        }
    }
    cout << n << " " << n << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 