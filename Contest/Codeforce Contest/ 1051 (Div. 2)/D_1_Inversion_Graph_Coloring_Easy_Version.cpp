// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 310, mod = 1e9 + 7;
int n, A[nn], Ans[nn][nn][nn];

int good(int mx1, int mx2, int i) {
    if (i > n) return 1;

    int &ans = Ans[i][mx1][mx2];
    if (ans != -1) return ans;

    ans = good(mx1, mx2, i + 1);

    if (A[i] >= mx2) {
        if (A[i] < mx1) ans += good(mx1, A[i], i + 1);
        else ans += good(A[i], mx2, i + 1);
    }

    ans %= mod;

    return ans;
}

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                Ans[i][j][k] = -1;
            }
        }
    }

    cout << good(0, 0, 1) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }

    return 0;
} 