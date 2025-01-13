// Created on: 2024-11-01 01:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    int a[n + 1];
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int mn = a[1], mx = a[1];
    for (int i = 2; i <= n; i++) {
        mx |= a[i];
        mn &= a[i];
    }

    cout << mx - mn << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 