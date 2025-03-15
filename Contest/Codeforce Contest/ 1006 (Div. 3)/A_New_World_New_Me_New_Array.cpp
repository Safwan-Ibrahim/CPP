// Created on: 2025-02-25 20:39
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, k, p; cin >> n >> k >> p;
    k = abs(k);
    
    if (n * p < k) {
        cout << -1 << endl;
    }
    else {
        cout << (k + p - 1) / p << endl;
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