// Created on: 2025-08-01 10:24
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int A[n + 1];
        if (n == 2) {
            cout << -1 << endl; continue;
        }
        iota(A + 1, A + n + 1, 1);
        sort(A + (n % 2 == 1 ? (n + 1) / 2 : n / 2 + 1), A + n + 1, greater<int>());
        if (n % 2 == 0) {
            swap(A[n / 2], A[(n / 2) - 1]);
        }
    
        for (int i = 1; i <= n; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
} 