// Created on: 2025-02-25 19:53
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, k; cin >> n >> k; k++;
    int A[n + 1];

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        A[i] = pow(10, x);
    }
    
    ll ans = 0;
    for (int i = 1; i + 1 <= n && k; i++) {
        int need = A[i + 1] / A[i] - 1; 
        ans += 1LL * min(k, need) * A[i];
        k -= min(k, need);
    }
    
    if (k) {
        ans += 1LL * k * A[n];
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 