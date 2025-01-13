// Created on: 2024-10-14 14:48
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void fast_solve() 
{
    int n, k; cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll total = 0;
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        mx = max(mx,a[i]);
        total += a[i];
    }

    ll ans = (total + k - 1) / k;
    cout << max((ll)mx,ans) << endl;
}

bool ok(ll x,ll total, int k) {
    return k >= (total + x - 1) / x;
}

void solve()
{
    int n, k; cin >> n >> k;
    int a[n + 1];
    int mx = -1;
    ll total = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        mx = max(a[i],mx);
        total += a[i];
    }

    ll lo = mx, hi = 1e15, ans = 1e15; 
    while(lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (ok(mid,total,k)) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) fast_solve();
    return 0;
} 