// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll inf = 1E9;

ll query(char c, ll k) {
    cout << "? " << c << " " << k << endl;
    ll ans; cin >> ans; return ans;
}

void Try() {
    ll n; cin >> n;

    ll mx = -1E15, mn = 1E15;
    for (int i = 1; i <= n; i++) {
        ll x, y; cin >> x >> y;
        mx = max(mx, x + y);
        mn = min(mn, y - x);
    }

    query('R', inf), query('R', inf), query('U', inf);
    ll d1 = query('U', inf);

    query('D', inf), query('D', inf), query('D', inf);
    ll d2 = query('D', inf);

    ll a = (d1 + d2 + mx - mn) / 2; 
    ll b = mx - a + d1;

    a -= inf * 4;

    cout << "! " << a << " " << b << endl;
}

int32_t main() {

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 