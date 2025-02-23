// Created on: 2025-02-18 21:04
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int n, m;
bool is_valid(int i, int j) {
    return 1 <= i && i <= n && 1 <= j && j <= m;
}

void Try() {
    cin >> n >> m;

    int A[n + 1][m + 1];
    map<int, int>Mp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
            Mp[A[i][j]] = 1;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (Mp[A[i][j]] == 2) {
                continue;
            }
            else if (is_valid(i + 1, j) && A[i][j] == A[i + 1][j]) {
                Mp[A[i][j]] = 2;
            }
            else if (is_valid(i - 1, j) && A[i][j] == A[i - 1][j]) {
                Mp[A[i][j]] = 2;
            }
            else if (is_valid(i , j + 1) && A[i][j] == A[i][j + 1]) {
                Mp[A[i][j]] = 2;
            }
            else if (is_valid(i, j - 1) && A[i][j] == A[i][j - 1]) {
                Mp[A[i][j]] = 2;
            }
        }
    }
    
    ll ans = 0;
    int mx = -1;
    for (auto [x, y] : Mp) {
        ans += y;
        mx = max(mx, y);
    }

    cout << ans - mx << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 