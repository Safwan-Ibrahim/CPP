// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 100 + 17, mod = 998244353;
int n, A[nn], B[nn];

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }

    vector<vector<int>> Way(2, vector<int>(n + 1, 0));
    Way[0][1] = 1; // not swap
    Way[1][1] = 1; // swap

    for (int i = 2; i <= n; i++) {
        if (A[i] >= A[i - 1] && B[i] >= B[i - 1]) {
            Way[0][i] += Way[0][i - 1];
            Way[0][i] %= mod;
            Way[1][i] += Way[1][i - 1];
            Way[1][i] %= mod;
        }
        if (A[i] >= B[i - 1] && B[i] >= A[i - 1]) {
            Way[0][i] += Way[1][i - 1];
            Way[0][i] %= mod;
            Way[1][i] += Way[0][i - 1];
            Way[1][i] %= mod;
        }
    }

    cout << (Way[0][n] + Way[1][n]) % mod << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 