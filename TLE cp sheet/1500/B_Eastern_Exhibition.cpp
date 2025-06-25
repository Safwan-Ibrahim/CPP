// Created on: 2025-05-09 05:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e3 + 8;
int n, A[2][nn];

int get_med(int row) {
    if (n & 1) {
        return 1;
    }
    else {
        return A[row][n / 2 + 1] - A[row][n / 2] + 1;
    }
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[0][i] >> A[1][i];
    }

    sort(A[0] + 1, A[0] + n + 1), sort(A[1] + 1, A[1] + n + 1);
    cout << 1LL * get_med(0) * get_med(1) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 