// Created on: 2025-01-07 19:38
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int m, n; cin >> m >> n;

    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; a[i] %= m;
    }

    for (int i = 1; i + 1 <= n; i++) {
        a[i + 1] = (a[i] + a[i + 1]) % m;
    }

    map<int,int>mp; ll ans = 0; mp[0]++;
    for (int i = 1; i <= n; i++) {
        ans += mp[a[i]]; 
        mp[a[i]]++;
    }
    
    cout << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 