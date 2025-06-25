// Created on: 2025-06-03 21:08
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 5e5 + 18;
int n, A[nn];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    ll ans = 2e18;
    for (int i = 1; i <= n;) {
        int st = i;
        while(i <= n && A[i] == A[st]) {
            i++;
        }
        ans = min(ans, 1LL * (st - 1) * A[st] + 1LL * (n - i + 1) * A[st]);
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