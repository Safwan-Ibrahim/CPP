// Created on: 2024-11-16 18:50
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n,b,c;

bool bs(ll x) {
    return b * x + c <= n - 1;
}

void solve()
{
    cin >> n >> b >> c;

    if (b == 0) {
        if (c >= n) {
            cout << n << endl;
        }
        else if (c == n - 1 || c == n - 2) {
            cout << n - 1 << endl;
        }
        else {
            cout << -1 << endl;
        }
        return;
    }

    ll ans = 0, lo = 0, hi = (n + b - 1) / b;
    while(lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (bs(mid)) {
            ans = mid + 1;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    
    cout << n - ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 