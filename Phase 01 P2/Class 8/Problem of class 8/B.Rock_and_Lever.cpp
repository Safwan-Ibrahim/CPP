// Created on: 2024-10-12 03:50
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    int a[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll ans = 0; map<int,int>mp;
    for (int i = 1; i <= n; i++) {
        int zero = __builtin_clz(a[i]);
        ans += mp[zero]++;
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