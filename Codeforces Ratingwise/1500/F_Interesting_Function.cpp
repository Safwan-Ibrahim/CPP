// Created on: 2025-03-17 00:53
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int l, r; cin >> l >> r;

    int ans = r - l;
    int n = to_string(r).size() - 1;
    for (int i = 1, pow_ten = 10; i <= n; i++, pow_ten *= 10) {
        int num = l - l % pow_ten + pow_ten - 1;
        if (num > r) {
            break;
        }
        int number_of_ten = (r - num + pow_ten - 1) / pow_ten;
        ans += number_of_ten;
    }
    cout << ans << endl;
    
}

void Better_try() {
    int l, r; cin >> l >> r;

    int ans = 0;
    while(r != 0) {
        ans += r - l;
        r /= 10, l /= 10;
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Better_try();
    }
    return 0;
} 