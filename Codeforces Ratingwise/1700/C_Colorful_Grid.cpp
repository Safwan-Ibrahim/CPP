// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, m, k; cin >> n >> m >> k;

    if (n + m - 2 > k || (n + m) % 2 != k % 2) {
        cout << "NO\n"; return;
    }
    
    vector<vector<bool>> A(n + 1, vector<bool> (m));
    vector<vector<bool>> B(m + 1, vector<bool> (n));

    bool x = true;
    B[m][n - 1] = B[m - 1][n - 1] = x;

    for (int j = m - 1; j >= 1; j--) {
        A[n][j] = x;
        x ^= 1;
    }
    
    A[n - 1][m - 1] = A[n][m - 1] ^ 1;

    for (int i = n - 1; i >= 1; i--) {
        B[1][i] = x;
        x ^= 1;
    }

    B[2][1] = B[1][1];
    A[1][1] = A[2][1] = B[2][1] ^ 1;

    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            cout << (A[i][j] ? 'R' : 'B') << " ";
        }
        cout << endl;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << (B[j][i] ? 'R' : 'B') << " ";
        }
        cout << endl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 