// Created on: 2025-02-11 00:37
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 9;
int A[N];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int extra = (A[i] - (2 * i + 1) % A[i]) % A[i];
        for (int j = i + 1 + extra; j <= n; j += A[i]) {
            if (1LL * A[i] * A[j] == i + j) {
                ans++;
            }
        }
    }
    
    cout << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 