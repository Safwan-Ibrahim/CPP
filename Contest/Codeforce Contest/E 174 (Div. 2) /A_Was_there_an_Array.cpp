// Created on: 2025-02-18 20:44
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    int A[n + 1];

    for (int i = 1; i <= n - 2; i++) {
        cin >> A[i];
    }
    
    for (int i = 1; i + 2 <= n - 2; i++) {
        if (A[i] == 1 && A[i + 1] == 0 && A[i + 2] == 1) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 