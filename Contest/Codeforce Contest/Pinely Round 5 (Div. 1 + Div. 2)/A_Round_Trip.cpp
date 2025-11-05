// Created on: 2025-10-30 22:39
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int r, lim, c, n; cin >> r >> lim >> c >> n;

    string S; cin >> S;
    int ans = 0;
    for (auto x : S) {
        if (x == '1') {
            ans++;
            r = max(0, r - c);
        }
        else if (r < lim) {
            ans++;
            r = max(0, r - c);
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