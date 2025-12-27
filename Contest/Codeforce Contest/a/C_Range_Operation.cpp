// Created on: 2025-11-14 21:18
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn]; ll Ps[nn];

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++) {
        Ps[i] = Ps[i - 1] + A[i];
    }

    ll mx = 0, mx_l = -1e18;
    for (int i = 1; i <= n; i++) {
        mx_l = max(1LL * -i * i + i + Ps[i - 1], mx_l);
        mx = max(1LL * i * i + i - Ps[i] + Ps[n] + mx_l, mx);
    }

    cout << mx << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 