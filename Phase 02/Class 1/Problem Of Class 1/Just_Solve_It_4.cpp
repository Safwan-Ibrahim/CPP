// Created on: 2025-01-02 06:18
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll LCM(ll a, ll b) {
    __int128_t ans = (__int128_t) a * b / gcd(a, b); // __int128_t
    if (ans > 1e18 + 9) {
        return -1;
    }
    else {
        return (ll) ans;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, l, r; cin >> n >> m >> l >> r;
    n = LCM(n, m);
    if (n == -1) {
        cout << 0 << endl; return 0;
    }
    ll ans = r / n - (l + n - 1) / n + 1;
    cout << ans << endl;
    return 0;
} 