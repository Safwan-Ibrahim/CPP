// Created on: 2025-06-21 17:44
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int rt(ll x) {
    ll ans = sqrt(x);
    while(1LL * ans * ans <= x) ans++;
    while(1LL * ans * ans > x) ans--;
    return ans;
}

void Try() {
    int n, m; cin >> n >> m;
    int A[n + 7];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    map<int, int>Mp;
    for (int i = 1; i <= n; i++) {
        int r; cin >> r;
        for (int len = 0; len <= r; len++) {
            Mp[A[i] + len] = max(Mp[A[i] + len], rt(1LL * r * r - 1LL * len * len) + 1);
            Mp[A[i] - len] = max(Mp[A[i] - len], rt(1LL * r * r - 1LL * len * len) + 1);
        }
    }

    ll ans = 0;
    for (auto [x, y] : Mp) {
        ans += 2 * y - 1;
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