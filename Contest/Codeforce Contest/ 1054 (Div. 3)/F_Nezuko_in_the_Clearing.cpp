// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int h, d; cin >> h >> d;

    if (h <= d + (d % 2 == 0)) {
        cout << (d + (d + 1) / 2 + (d % 2)) << endl;
        return;
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