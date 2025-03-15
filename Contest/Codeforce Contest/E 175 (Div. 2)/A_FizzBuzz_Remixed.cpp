// Created on: 2025-02-27 20:41
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    int ans = n / 15 * 3;
    int ex = n % 15;
    ans += 1 ;
    if (ex > 0) {
        ans++;
    }    
    if (ex > 1) {
        ans++;
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