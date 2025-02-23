// Created on: 2025-02-11 01:41
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    string S; cin >> S;

    int cnt = 0;
    for (auto x : S) {
        cnt += x == '0';
    }

    if (n == 1 && cnt == 0) {
        cout << "DRAW\n";
    }
    if (n % 2 == 1 && S[n / 2] == '0' && cnt != 1) {
        cout << "ALICE\n";
    }
    else {
        cout << "BOB\n";
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 