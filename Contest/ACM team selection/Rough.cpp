// Created on: 2025-02-09 14:48
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n, m; cin >> n >> m;
    if (n & 1) {
        bool st = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << (st ? '(' : ')');
                st ^= 1;
            }
            cout << endl;
        }
        return;
    }

    if (m & 1) {
        bool st = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << (st ? '(' : ')');
            }
            cout << endl;
            st ^= 1;
        }
        return;
    }
    
    int mx = max(n, m), mn = min(n, m);
    char A[mx + 5][mn + 5];
    for (int i = 1; i <= mx; i++) {
        A[i][1] = '(';
        A[i][mn] = ')';
    }

    bool st = 1;
    for (int i = 1; i <= mx; i++) {
        if (i & 1) {
            st = 1;
        }
        else {
            st = 0;
        }
        for (int j = 2; j <= mn - 1; j++) {
            A[i][j] = (st ? '(' : ')');
            st ^= 1;
        }
    }

    if (n == mx) {
        for (int i = 1; i <= mx; i++) {
            for (int j = 1; j <= mn; j++) {
                cout << A[i][j];
            }
            cout << endl;
        }
        return;
    }

    for (int i = 1; i <= mn; i++) {
        for (int j = 1; j <= mx; j++) {
            cout << A[j][i];
        }
        cout << endl;
    }
    return;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 