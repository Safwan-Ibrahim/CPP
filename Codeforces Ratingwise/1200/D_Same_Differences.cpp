// Created on: 2025-02-08 02:23
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 9;
int A[N];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    map<int, int>Mp;
    ll ans = 0;
    for (int i = n; i >= 1; i--) {
        ans += Mp[i - A[i]];
        Mp[i - A[i]]++;
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