// Created on: 2025-07-06 20:45
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
    
    for (int i = 1; i + 1 <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (A[i] > A[j]) {
                cout << "YES\n";
                cout << 2 << endl;
                cout << A[i] << " " << A[j] << endl; return;
            }
        }
    }
        
    cout << "NO\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 