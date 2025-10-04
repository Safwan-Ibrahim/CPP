// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, kx, ky, dx, dy; cin >> n >> kx >> ky >> dx >> dy;
    
    int ans = max(abs(kx - dx), abs(dy - ky));
    
    if (dx < kx) ans = max(ans, n - dx);
    if (dx > kx) ans = max(ans, dx);
    if (dy < ky) ans = max(ans, n - dy);
    if (dy > ky) ans = max(ans, dy);

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