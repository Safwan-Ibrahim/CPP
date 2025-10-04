// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, m; cin >> n >> m;

    int A[m + 1];
    bool one = 0;
    for (int i = 1; i <= m; i++) {
        cin >> A[i];
        if (i > 1 && A[i] == 1) one = true;
    }

    if (one) {
        cout << 1 << endl; return;
    }

    cout << n - A[m] + 1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 