// Created on: 2025-02-14 21:03
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int A[6][6];
    int n = 5;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i][j] == 1) {
                cout << abs(3 - i) + abs(3 - j) << endl;
                return 0;
            }
        }
    }
    
    return 0;
} 