// Created on: 2025-05-03 02:51
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, m; cin >> n >> m;

    int store = n;
    int two = 0, five = 0;
    while(n > 0 && n % 2 == 0) {
        two++;
        n /= 2;
    }

    while(n > 0 && n % 5 == 0) {
        five++;
        n /= 5;
    }

    int k = 1;
    while(five > two && 2 * k <= m) {
        two++;
        k *= 2;
    }

    while(two > five && 1LL * k * 5 <= m) {
        five++;
        k *= 5;
    }

    while(1LL * k * 10 <= m) {
        k *= 10;
    } 

    cout << 1LL * (m / k) * k * store << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 