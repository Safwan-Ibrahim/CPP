// Created on: 2025-07-09 11:26
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e6 + 17, mod = 1e9 + 7;
int n = 1e6;
vector<vector<int>>Way(3, vector<int>(nn, 0));

void prec() {
    Way[1][1] = 1, Way[2][1] = 1;
    for (int i = 2; i <= n; i++) {
        Way[1][i] = ((Way[1][i - 1] * 2 % mod) + Way[2][i - 1]) % mod;
        Way[2][i] = ((1LL * Way[2][i - 1] * 4 % mod) + Way[1][i - 1]) % mod;
    }
}

void Try() {
    cin >> n;
    cout << (Way[1][n] + Way[2][n]) % mod << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1; cin >> t; prec();
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 