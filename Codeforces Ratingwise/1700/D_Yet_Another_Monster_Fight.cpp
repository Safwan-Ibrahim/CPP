// Created on: 2025-08-24 06:13
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 3e5 + 17;
int n, A[nn], Pmx[nn], Smx[nn];

bool ok(int x) {
    for (int i = 1; i <= n; i++) {
        if (Pmx[i - 1] <= x && Smx[i + 1] <= x && A[i] <= x) return true;
    }
    return false;
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, A[i] + n - i);
        Pmx[i] = mx;
    }
    mx = 0;
    for (int i = n; i >= 1; i--) {
        mx = max(mx, A[i] + i - 1);
        Smx[i] = mx;
    }
    Pmx[0] = -2e9, Smx[n + 1] = -2e9;
    
    int lo = 1, hi = 2e9, ans;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (ok(mid)) ans = mid, hi = mid - 1;
        else lo = mid + 1;
    }

    cout << ans << endl;   
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; //cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 