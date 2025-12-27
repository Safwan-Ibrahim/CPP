// Created on: 2025-11-10 21:09
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;

    int A[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    sort(A + 1, A + n + 1);
    for (int i = 2; i <= n - 1; i += 2) {
        if (A[i + 1] > A[i]) {
            cout << "NO\n"; return;
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