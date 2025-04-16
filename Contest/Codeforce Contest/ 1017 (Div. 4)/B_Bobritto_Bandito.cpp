// Created on: 2025-04-13 21:43
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, m, l, r; cin >> n >> m >> l >> r;
    int lp = abs(0 - l), rp = abs(r - 0);
    if (m <= lp) {
        cout << 0 - m << " " << 0 << endl;
    }
    else if (m <= rp) {
        cout << 0 << " " << m << endl;
    }
    else {
        m -= lp;
        cout << l << " " << m << endl;
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