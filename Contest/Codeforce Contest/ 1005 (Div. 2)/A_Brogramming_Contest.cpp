// Created on: 2025-02-16 20:38
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    string S; cin >> S;
    int cnt = 0;

    bool look_one = true;
    for (auto x : S) {
        if (look_one && x == '1') {
            cnt++;
            look_one ^= 1;
        }
        else if (!look_one && x == '0') {
            cnt++;
            look_one ^= 1;
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