// Created on: 2025-06-12 20:38
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cout << '1';
    }
    for (int i = 1; i <= n - k; i++) {
        cout << '0';
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