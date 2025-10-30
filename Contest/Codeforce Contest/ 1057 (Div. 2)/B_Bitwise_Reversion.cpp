// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int x, y, z; cin >> x >> y >> z;

    for (int k = 30; k >= 0; k--) {
        int c = (x >> k) & 1;
        c += (y >> k) & 1;
        c += (z >> k) & 1;
        if (c == 2) {
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