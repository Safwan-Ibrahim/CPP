// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void Try() {
    int n; cin >> n;

    int x = 0;
    for (int i = 1; !x && i < n; i++) {
        for (int j = i + 1; !x && j <= n; j++) {
            cout << i << " " << j << endl;
            cin >> x;
        }
    }
    
}

int32_t main() {

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 