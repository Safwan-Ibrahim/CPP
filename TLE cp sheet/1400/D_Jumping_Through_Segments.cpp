// Created on: 2025-04-30 19:39
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, L[nn], R[nn];

bool ok(int x) {
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        int next_l = l - x, next_r = r + x;
        if (next_r < L[i] || next_l > R[i]) {
            return 0;
        }
        l = max(next_l, L[i]);
        r = min(next_r, R[i]);
    }
    return 1;
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> L[i] >> R[i];
    }
    
    int lo = 0, hi = 1e9 + 10, ans;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if (ok(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
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