// Created on: 2025-01-26 20:36
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    string s; cin >> s;
    int cnt = 0;
    for (auto x : s) {
        if (x == '1') {
            cnt++;
        }
    }
    cout << cnt << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 