// Created on: 2025-06-28 21:37
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, m, k; cin >> n >> m >> k;
    int A[n + 1][m + 1], T[n + 1][m + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
    }

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c; cin >> c;
            T[i][j] = c == '1';
            if (c == '1') sum += A[i][j];
            else sum -= A[i][j];
        }
    }

    sum = abs(sum);

    vector<vector<int>>Ps(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            Ps[i][j] = T[i][j] + Ps[i - 1][j] + Ps[i][j - 1] - Ps[i - 1][j - 1];
        }
    }

    int gcd_ = 0;
    for (int i = 1; i + k - 1 <= n; i++) {
        for (int j = 1; j + k - 1 <= m; j++) {
            int up = i, down = i + k - 1, lft = j, rgt = j + k - 1;
            int one = Ps[down][rgt] + Ps[up - 1][lft - 1] - Ps[up - 1][rgt] - Ps[down][lft - 1];
            gcd_ = gcd(gcd_, abs(2 * one - k * k));
        }
    }
    if (gcd_ != 0 && sum % gcd_ == 0 || sum == 0) {
        cout << "YES\n";
    }
    else cout << "NO\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 