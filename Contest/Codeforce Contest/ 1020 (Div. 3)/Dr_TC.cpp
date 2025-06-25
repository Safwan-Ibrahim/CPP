// Created on: 2025-04-24 20:39
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    string S; cin >> S;
    int cnt = 0;
    for (auto x : S) {
        cnt += x == '1';
    }

    int ans = 0;
    for (auto x : S) {
        if (x == '1') {
            ans += cnt - 1;
        }
        else {
            ans += cnt + 1;
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