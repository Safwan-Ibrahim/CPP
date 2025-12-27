// Created on: 2025-04-30 01:40
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int ans = 0;
    int n; cin >> n;
    int last_mn = 2e9 + 8, last_mx = 2e9 + 8;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (last_mn > last_mx) {
            swap(last_mn, last_mx);
        }
        if (x > last_mx) {
            ans++;
            last_mn = x;
        }
        else if (x > last_mn && x <= last_mx) {
            last_mx = x;
        }
        else {
            last_mn = x;
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