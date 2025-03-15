// Created on: 2025-03-10 20:51
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, k; cin >> n >> k;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        sum += x;
    }
    
    if (sum % n == 0 && sum / n == k) {
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