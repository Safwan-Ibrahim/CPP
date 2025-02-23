// Created on: 2025-02-15 17:16
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 7;
int A[N];

void solve() {
    int n; ll k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    map<int, int>Mp;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        Mp[A[i]] = x;
    }

    ll mx = 0;
    ll prev = 0;
    for (auto [x, y] : Mp) {
        if (Mp.find(x - 1) != Mp.end()) {

            int taken_prev = min(k / (x - 1), prev);
            ll left = k - min(k / (x - 1), prev) * (x - 1);
            int left_y = y - min(left / x, 1LL * y);
            left = left - min(left / x, 1LL * y) * x;

            left -= min(left, 1LL * min(taken_prev, left_y));
            mx = max(mx, k - left);
        }
        else {
            ll highest = k / x;
            mx = max(mx, min(1LL * y * x, highest * x)); 
        }
        prev = y;
    }

    cout << mx << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 