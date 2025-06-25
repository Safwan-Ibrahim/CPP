// Created on: 2025-05-08 18:17
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, a, b, A[nn];

void Try() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    ll ans = 0;
    int cur = 0, ind = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1LL * b * (A[i] - cur);
        int rest = n - (ind + 1);
        if (1LL * rest * b * (A[i] - cur) >= 1LL * a * (A[i] - cur)) {
            ans += 1LL * a * (A[i] - cur);
            cur = A[i];
            ind++;
        }
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