// Created on: 2025-06-21 18:27
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int rt(ll x) {
    int ans = sqrt(x);
    while(1LL * ans * ans <= x) ans++;
    while(1LL * ans * ans > x) ans--;
    return ans;
}

ll points_smller_than_r(int x) {
    ll ans = 0;
    for (int p = -x; p <= x; p++) {
        ll y_y = (1LL * x * x) - (1LL * p * p); 
        if (y_y == 0) continue;
        int y = rt(y_y);
        if (y_y > 1LL * y * y) y++;
        ans += 2 * y - 1;
    }
    return ans;
}

void Try() {
    int r; cin >> r;
    cout << points_smller_than_r(r + 1) - points_smller_than_r(r) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 