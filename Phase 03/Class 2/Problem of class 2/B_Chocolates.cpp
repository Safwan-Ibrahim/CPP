// Created on: 2025-07-13 20:22
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int A[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    ll ans = 0; int mn = 2e9;
    for (int i = n; i >= 1; i--) {
        mn = min(mn - 1, A[i]);
        ans += max(0, mn);
    }

    cout << ans << endl;
    
    return 0;
} 