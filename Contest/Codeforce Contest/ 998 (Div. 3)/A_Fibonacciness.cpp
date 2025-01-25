// Created on: 2025-01-19 20:40
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int a[10];

int check() {
    int ans = 0;
    if (a[3] == a[2] + a[1]) {
        ans++;
    }
    if (a[4] == a[3] + a[2]) ans++;
    if (a[5] == a[4] + a[3]) ans++;
    return ans;
}

void solve() {

    for (int i = 1; i <= 5; i++) {
        if (i == 3) {
            continue;
        }
        cin >> a[i];
    }

    int ans = -1;
    a[3] = a[1] + a[2];
    ans = max(ans, check());
    a[3] = a[4] - a[2];
    ans = max(ans, check());
    a[3] = a[5] - a[4];
    ans = max(ans, check());

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