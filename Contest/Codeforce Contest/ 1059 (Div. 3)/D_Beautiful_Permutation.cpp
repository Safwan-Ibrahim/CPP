// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define int long long

int query(int t, int l, int r) {
    cout << t << " " << l << " " << r << endl;
    int ans; cin >> ans; return ans;
}

void Try() {
    int n; cin >> n;

    int len = query(2, 1, n) - query(1, 1, n);

    int lo = 1, hi = n, ans = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        bool ok = query(2, lo, mid) > query(1, lo, mid);
        if (ok) {
            hi = mid;
            ans = mid;
        }
        else lo = mid + 1;
    }


    cout << "! " << ans << " " << ans + len - 1 << endl;
    
}

int32_t main() {

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 