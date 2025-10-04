// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn];

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    ll mn = 1e17, mx = -mn, add = 0, ans = 0;
    
    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            ans += A[i];
            mn = min(mn, 2LL * A[i] + i);
            add = max(add, i - 2 * A[i] + mx);
        }
        else {
            ans -= A[i];
            add = max(add, 2 * A[i] + i - mn);
            mx = max(mx, 2LL * A[i] - i);
        }
    }

    if (n & 1) add = max(add, 1LL * n - 1);
    else add = max(add, 1LL * n - 2);

    ans += add;
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