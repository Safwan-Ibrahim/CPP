// Created on: 2024-10-08 23:34
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool is_set(ll n, int k) {
    return (n >> k & 1); 
}

void solve()
{
    ll x; cin >> x;
    ll an = (x << 1);

    if (x == 0) {
        cout << 1 << endl; return;
    }

    ll ans = 0;
    for (int i = 0; i < 63; i++) {
        if (is_set(an,i) && is_set(x,i)) {
            cout << 0 << endl; return;
        }
        if (!is_set(an,i) && is_set(x,i)) {
            ans++;     
        }
    }
    cout << (1LL << ans) << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 