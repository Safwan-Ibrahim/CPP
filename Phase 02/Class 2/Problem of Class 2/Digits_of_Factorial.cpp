// Created on: 2025-01-09 09:15
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e6 + 7;
double log_base10[N];

void prec() {
    for (int i = 1; i < N; i++) {
        log_base10[i] = log10(i) + log_base10[i - 1];
    }
}

void solve(int t) {
    int n, x; cin >> n >> x;
    ll digit_base_x = floor((log(10) / log(x)) * log_base10[n]);

    cout << "Case " << t << ": ";
    cout << digit_base_x + 1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    prec();
    int t = 1; cin >> t; int c = 1;
    while(t--) solve(c++);
    return 0;
} 