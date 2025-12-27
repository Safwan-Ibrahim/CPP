// Created on: 2025-11-30 09:25
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int x; cin >> x;
    
    if ((x & (x + 1)) == 0) {
        cout << x + 1 << endl;
    }
    else {
        int msb = __lg(x);
        cout << (1 << msb) << endl;
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