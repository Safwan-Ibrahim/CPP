// Created on: 2025-07-09 19:46
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    if (n == 1 || n == 2 || n == 3) {
        cout << n - 1 << endl;
    }
    else if (n % 2 == 0) {
        cout << 2 << endl;
    } 
    else cout << 3 << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 