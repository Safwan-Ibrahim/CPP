// Created on: 2025-06-28 17:08
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int ans; cin >> ans; return ans; 
}

void Try() {
    int lo = 1, hi = 999;
    while (hi - lo > 1) {
        int l = lo + (hi - lo) / 3;
        int r = lo + (hi - lo) * 2 / 3;
        int ans = query(l, r);
        if (ans == l * r) {
            lo = r;
        }
        else if (ans - l == l * r) {
            hi = r; lo = l;
        }
        else hi = l;
    }
    cout << "! " << hi << endl;
}

int32_t main() {
    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 