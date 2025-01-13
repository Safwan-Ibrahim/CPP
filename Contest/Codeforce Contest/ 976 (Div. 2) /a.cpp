// Created on: 2024-10-07 12:14
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n,k; cin >> n >> k;

    if (k == 1) {
        cout << n << endl; return;
    }

    int ans = 0;
    while(n) {
        ans += n % k;
        n /= k;
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