// Created on: 2025-05-20 19:54
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e3 + 8;
int n, k, A[nn];

bool ok(int x) {
    for (int i = 1; i <= n; i++) {
        int have = k, need = x;
        for (int j = i; j <= n; j++) {
            if (A[j] >= need) return true;
            if (have < need - A[j] || j == n) break;
            have -= need - A[j];
            need--;
        }
    }
    return false;
}

void Try() {
    int mx = -1; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        mx = max(mx, A[i]);
    }
    
    int lo = mx + 1, hi = 1e9;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (ok(mid)) {
            mx = max(mx, mid);
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
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