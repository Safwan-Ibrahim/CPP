// Created on: 2025-07-05 20:39
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int a, b, x, y; cin >> a >> b >> x >> y;
    if (a > b) {
        if ((a ^ 1) == b) cout << y << endl;
        else cout << -1 << endl;
        return;
    }
    
    int ans = (b - a) * x; b--;
    int even_cnt = (b - a + 1) / 2 + ((b % 2 == 0) && (a % 2 == 0));
    ans -= max(even_cnt * (x - y), 0);
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