// Created on: 2024-11-05 20:16
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool ok(int x,ll have) {
    ll sum = 1LL * x * (x + 1) / 2;
    return sum > have;
}

void solve()
{
    int n; cin >> n;
    int a[n + 1];
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int ans = 1;
    int lo = 1, hi = 1e9 + 7;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (ok(mid,sum)) {
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
    while(t--) solve();
    return 0;
} 