// Created on: 2025-11-28 20:37
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;

    vector<vector<int>> A(n + 2, vector<int> (n + 2, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            A[i][j] = j + (i - 1) * n;
        }
    }

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mx = max(mx, A[i][j] + A[i + 1][j] + A[i - 1][j] + A[i][j + 1] + A[i][j - 1]);
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