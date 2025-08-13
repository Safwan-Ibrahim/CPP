// Created on: 2025-08-06 21:36
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

__int128 get_sum(__int128 n) {
    return n * (n - 1) / 2;
}

void Try() {
    ll n; cin >> n;
    ll lo = 2, hi = n, ans = max(2LL, n);
    while(lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (get_sum(mid) <= n) {
            ans = mid + (n - get_sum(mid));
            lo = mid + 1;
        }
        else hi = mid - 1;
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 