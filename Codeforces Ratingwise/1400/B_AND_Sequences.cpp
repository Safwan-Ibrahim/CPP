// Created on: 2025-03-08 00:16
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int M = 1e9 + 7, N = 2e5 + 10;
int Fact[N];

void prec() {
    Fact[0] = 1;
    for (int i = 1; i < N - 2; i++) {
        Fact[i] = 1LL * Fact[i - 1] * i % M;
    }
}

void Try() {
    int n; cin >> n;
    int check_and = ~(0);
    map<int, int>Mp;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        check_and &= x;
        Mp[x]++;
    }

    int ans = 0;
    for (auto [x, y] : Mp) {
        if (y >= 2 && (check_and & x) == x) {
            int np = 1LL * Fact[n - 2] * y % M * (y - 1) % M;
            ans = (ans + np) % M;
        }
    }

    cout << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    prec();
    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 