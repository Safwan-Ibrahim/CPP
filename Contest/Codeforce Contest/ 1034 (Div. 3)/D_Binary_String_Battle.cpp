// Created on: 2025-07-01 21:25
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, k; cin >> n >> k;
    string S; cin >> S;
    int cnt = 0;
    for (auto x : S) {
        cnt += x == '1';
    }
    
    if (cnt <= k || k >= n / 2 + 1) {
        cout << "Alice\n";
    }
    else cout << "Bob\n";
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 