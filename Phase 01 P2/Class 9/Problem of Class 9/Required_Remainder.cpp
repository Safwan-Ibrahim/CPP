// Created on: 2024-11-25 18:27
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int x, y, n; cin >> x >> y >> n;
    int ml = n / x;
    if (1LL * ml * x + y <= n) {
        cout << 1LL * ml * x + y << endl;
    }
    else {
        cout << 1LL * --ml * x + y << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 