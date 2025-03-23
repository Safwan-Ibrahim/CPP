// Created on: 2025-03-23 11:51
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, m; cin >> n >> m;
    char A[n + 5][m + 5];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
    } 
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (A[i][j] == '1') {
                bool one = true, two = true;
                for (int k = 1; k <= i; k++) {
                    if (A[k][j] != '1') {
                        one = false;
                    }
                }
                for (int k = 1; k <= j; k++) {
                    if (A[i][k] != '1') {
                        two = false;
                    }
                }
                if (!one && !two) {
                    cout << "NO\n"; return;
                }
            }

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