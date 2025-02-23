// Created on: 2025-02-23 01:48
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {

    int n; cin >> n;
    int ex = n / 111;
    
    if (ex >= n % 11) {
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