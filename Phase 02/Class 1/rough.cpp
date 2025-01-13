// Created on: 2024-12-31 23:15
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    int a[n + 1];
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; 
        sum += a[i];
    }   

    int ans = (3 - sum % 3) % 3;
    for (int i = 1; i <= n; i++) {
        if (a[i] % 3 == sum % 3) {
            ans = min(1, ans);
        }
    }

    cout << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 