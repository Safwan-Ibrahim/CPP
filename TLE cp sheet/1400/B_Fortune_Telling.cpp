// Created on: 2025-05-04 16:24
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int nn = 1e5 + 8;
int n, x;
long long y;

void Try() {
    cin >> n >> x >> y;
    long long sum = x;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        sum += x;
    }

    if (sum % 2 == y % 2) {
        cout << "Alice\n";
    }
    else {
        cout << "Bob\n";
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