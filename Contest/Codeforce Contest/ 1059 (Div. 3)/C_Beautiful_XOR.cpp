// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int a, b; cin >> a >> b;

    int msb = __lg(a);
    int all = (1LL << (msb + 1)) - 1;

    if (b > all) {
        cout << -1 << endl;
    }
    else {
        cout << 2 << endl;
        int x = (a ^ all);
        int y = (all ^ b);
        assert((a ^ x ^ y) == b);
        cout << x << " " << y << endl;
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