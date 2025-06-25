// Created on: 2025-04-16 22:05
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int A[n + 1];
    int sum = 0;
    bool all_zero = true;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        sum += A[i];
        if (A[i] != 0) {
            all_zero = false;
        }
    }

    if (all_zero) {
        cout << "NO\n"; return 0;
    }
    if (sum != 0) {
        cout << "YES\n";
        cout << 1 << endl;
        cout << 1 << " " << n << endl;
        return 0;
    }   

    sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += A[i];
        if (sum != 0) {
            cout << "YES\n";
            cout << 2 << endl;
            cout << 1 << " " << i << endl;
            cout << i + 1 << " " << n << endl;
            return 0;
        }
    }

    return 0;
} 