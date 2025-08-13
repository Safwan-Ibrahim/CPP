// Created on: 2025-08-06 18:12
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int n, A[nn];

void Try() {
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i]; A[i] = abs(A[i]);
        mx = max(mx, A[i]);
    }

    int ans = 1, r = 1; ll sum = 0;
    for (int l = 1; l <= n; l++) {
        while(r <= n && sum + A[r] <= mx) {
            sum += A[r++]; 
        }
        if (sum == mx) ans = max(ans, r - l);
        sum -= A[l];
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