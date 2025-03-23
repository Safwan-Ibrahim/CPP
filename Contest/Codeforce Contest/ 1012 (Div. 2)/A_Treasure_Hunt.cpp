// Created on: 2025-03-23 11:41
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int x, y, a; cin >> x >> y >> a;
    int sum = x + y;
    int k = a / sum;
    a -= k * sum;
    if (a < x) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
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