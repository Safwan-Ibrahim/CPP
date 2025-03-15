// Created on: 2025-03-11 20:55
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int y;

int first(int x) {
    for (int i = 30; i >= 0; i--) {
        if ((x >> i) & 1) {
            return i;
        }
    }
}

void on_bit(int k) {
    y = (1 << k) | y;
    return;
}

void off_bit(int k) {
    int a = ~(1 << k);
    y = a & y;
    return;
}

void Try() {
    int x; cin >> x;
    int first_one = first(x);
    y = 0;
    for (int i = first_one; i >= 0; i--) {
        if (!((x >> i) & 1)) {
            on_bit(i);
        }
    }
    
    for (int i = 0; i <= first_one; i++) {
        if ((x >> i) & 1) {
            on_bit(i); break;
        }
    }

    int cnt = 0;
    for (int i = first_one; i >= 0; i--) {
        if ((x >> i) & 1) {
            cnt++;
        }
    }

    if (cnt == 1) {
        cout << -1 << endl; return;
    }
    int z = x ^ y;
    if (x + y > z && x + z > y && y + z > x) {
        cout << y << endl;
    }
    else {
        cout << -1 << endl;
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 