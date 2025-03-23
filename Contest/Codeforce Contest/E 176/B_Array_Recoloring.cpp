// Created on: 2025-03-17 20:58
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, k; cin >> n >> k;
    ll A[n + 5];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    ll mx = -1;
    if (k == 1) {
        ll a = A[1], b = A[n];
        mx = max(mx, a + b);
        for (int i = 2; i <= n - 1; i++) {
            mx = max(mx, A[i] + max(a, b));
        }
        cout << mx << endl; return;
    }
    
    sort(A + 1 , A + n + 1);
    ll ans = 0;
    for (int i = n, j = 1; j <= k + 1; j++, i--) {
        ans += A[i];
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