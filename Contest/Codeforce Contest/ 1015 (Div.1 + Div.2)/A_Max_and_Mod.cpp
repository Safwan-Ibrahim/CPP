// Created on: 2025-04-19 17:48
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    if (n % 2 == 0) {
        cout << -1 << endl; return;
    }
    cout << n << " ";
    for (int i = 1; i < n; i++) {
        cout << i << " ";
    }
    cout << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 