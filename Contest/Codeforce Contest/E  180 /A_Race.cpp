// Created on: 2025-06-23 20:38
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int a, x, y; cin >> a >> x >> y;
    if (x > y) swap(x, y);
    if (a < x || a > y) {
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