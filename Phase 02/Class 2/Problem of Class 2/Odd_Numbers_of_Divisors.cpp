// Created on: 2025-01-08 19:55
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int k; ll l, r;
const int N = 1e5, K = 1e5;
vector<ll> valid[K + 1];

void dvs(int n) {
    ll num = 1LL * n * n;
    int d = 1;
    for (int i = 2; i * i <= n; i++) {
        int p = 0;
        while(n % i == 0) {
            n /= i;
            p++;
        }
        d *= p * 2 + 1;
    }
    if (n > 1) {
        d *= 3;
    }
    valid[d].push_back(num);
}

void prec() {
    for (int i = 1; i < N; i++) {
        dvs(i);
    }
}

void solve() {
    cin >> k >> l >> r;

    auto rm = upper_bound(valid[k].begin(), valid[k].end(), r);
    auto lm = lower_bound(valid[k].begin(), valid[k].end(), l);
    cout << rm - lm << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    prec();
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 