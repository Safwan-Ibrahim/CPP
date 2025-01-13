// Created on: 2024-10-31 23:05
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool is_set(ll x, int k) {
    return (x >> k) & 1;
}

ll off_bit(ll x, int k) {
    x = (~(1LL << k)) & x;
    return x;
}

void solve() 
{
    ll l,r; cin >> l >> r;
    for (int i = 63; i >= 0; i--) {
        if (!is_set(l,i) && is_set(r,i)) {
            ll need = off_bit(r,i);
            ll ans = ((1LL << i) - 1) | need;
            if (__builtin_popcountll(ans) >= __builtin_popcountll(r)) {
                cout << ans << endl; return;
            }
            else {
                cout << r << endl; return;
            }
        }
    }
    cout << r << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 