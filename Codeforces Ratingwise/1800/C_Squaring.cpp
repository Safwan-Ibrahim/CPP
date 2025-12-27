// Created on: 2025-12-04 13:47
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool ok(int x, int px, int y, int py) {
    
    bool rev = 0, ans = 0;
    if (py < px) {
        swap(py, px);
        swap(x, y);
        rev = 1;
    }

    if (y >= x) {
        ans = 1; 
    }
    
    ll lim = 1;
    for (int i = 1; i <= py - px && !ans; i++) {
        lim <<= 1;
        if (lim >= x && !rev || lim > x && rev) ans = 1;
    }
    
    ll ny = 1;
    for (int i = 1; i <= lim && !ans; i++) {
        ny *= y;
        if (ny >= x && !rev || ny > x && rev) ans = 1;
    }

    return ans ^ rev;
}

void Try() {
    int n; cin >> n;

    int x, y, last = 0;
    cin >> x; ll ans = 0; bool pos = 1;
    
    for (int i = 1; i < n; i++) {
        cin >> y;

        if (y == 1 && x > 1) {
            pos = 0;
        }

        if (!pos) continue;

        int lo = 0, hi = 1e9, need = -1;

        while (lo <= hi) {
            int mid = lo + hi >> 1;

            if (ok(x, last, y, mid)) {
                need = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        ans += need;
        last = need;
        x = y;
    }

    cout << (pos ? ans : -1) << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 