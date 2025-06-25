// Created on: 2025-06-17 20:52
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'


void Try() {
    int n, m; cin >> n >> m;
    int A[n + 10][m + 10];
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
            mx = max(mx, A[i][j]);
        }
    }
    
    int tt = 0;
    int Mx_cnt_row[n + 10][m + 10], Mx_cnt_col[n + 10][m + 10];
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= m; j++) {
            cnt += A[i][j] == mx;
            tt += A[i][j] == mx;
        }
        for (int j = 1; j <= m; j++) {
            Mx_cnt_row[i][j] = cnt;
        }
    }

    for (int col = 1; col <= m; col++) {
        int cnt = 0;
        for (int row = 1; row <= n; row++) {
            cnt += A[row][col] == mx;
        }
        for (int row = 1; row <= n; row++) {
            Mx_cnt_col[row][col] = cnt;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cnt = Mx_cnt_col[i][j] + Mx_cnt_row[i][j];
            cnt -= A[i][j] == mx;
            if (cnt == tt) {
                cout << mx - 1 << endl; return;
            }
        }
    }
    cout << mx << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 