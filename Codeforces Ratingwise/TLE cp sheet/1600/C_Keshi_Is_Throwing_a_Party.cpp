// Created on: 2025-05-27 04:42
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 18;
int n, R[nn], P[nn];

bool ok(int x) {
    int r = x - 1, p = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (R[i] >= r && P[i] >= p) {
            cnt++; r--; p++;
        }
        if (cnt == x) return 1;
    }
    return 0;
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> R[i] >> P[i];
    }
    
    int lo = 2, hi = n, ans = 1;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (ok(mid)) {
            ans = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
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