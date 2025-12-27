// Created on: 2025-11-20 21:10
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    
    int A[n + 2], B[n + 1];

    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        a ^= A[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> B[i];
        b ^= B[i];
    }
    
    if (a == b) {
        cout << "Tie\n"; return;
    }

    int i = n;
    while (A[i] == B[i]) i--;

    if (i & 1) {
        cout << "Ajisai\n";
    }
    else cout << "Mai\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 