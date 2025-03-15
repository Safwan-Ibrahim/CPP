// Created on: 2025-02-26 10:46
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int x, a, b; cin >> x >> a >> b;
    int s = abs(x - a), m = abs(x - b);

    if (s < m) {
        cout << "7vai\n";
    }
    else if (m < s) {
        cout << "3vai\n";
    }
    else {
        cout << "mojo\n";
    }
    
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; //cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 