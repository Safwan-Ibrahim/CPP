// Created on: 2025-04-13 23:43
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    int A[n + 1];
    map<int, int>B;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        for (int k = 29; k >= 0; k--) {
            int bit = (A[i] >> k) & 1;
            if (bit == 1) {
                B[k]++;
            }
        }
    }

    ll mx = 0;
    for (int i = 1; i <= n; i++) {
        ll ans = 0;
        for (int k = 0; k <= 29; k++) {
            int bit = (A[i] >> k) & 1;
            if (bit) {
                int cnt = n - B[k];
                ans += 1LL * cnt * (1LL << k);
            }
            else {
                ans += 1LL * B[k] * (1LL << k);
            }
        }
        mx = max(mx, ans);
    }

    cout << mx << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 