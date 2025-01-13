// Created on: 2024-12-31 22:40
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e6 + 9;
int sum[N];

void div_sum() {
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            sum[j] += i;
        }
    }
}

void solve() {
    int n; cin >> n; cout << sum[n] - n << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); div_sum();
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 