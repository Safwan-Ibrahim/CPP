// Created on: 2025-06-21 21:11
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, s; cin >> n >> s;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int d, e, x, y; cin >> d >> e >> x >> y;
        if (x + y == s || x == y) {
            if (x + y == s && x == y) ans++;
            else if (x == y && abs(d + e) == 2) ans++;
            else if (x + y == s && abs(d + e) == 0) ans++;
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