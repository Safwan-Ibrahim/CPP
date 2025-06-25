// Created on: 2025-06-08 20:12
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int query(int i, int j, int k) {
    assert(i != j && j != k && i != k);
    cout << "? " << i << " " << j << " " << k << endl;
    int ans; cin >> ans; 
    if (ans == 0) cout << "! " << i << " " << j << " " << k << endl;
    return ans;
}

void Try() {
    int n; cin >> n;
    vector<int>P = {1, 2, 3};
    bool type = 1; int mid;
    for (int i = 1; i <= 35; i++) {
        if (type) {
            mid = query(P[0], P[1], P[2]);
            if (mid == 0) return;
        }
        else {
            int a = query(P[0], P[1], mid);
            if (a == 0) return;
            int b = query(P[0], P[2], mid);
            if (b == 0) return;
            int c = query(P[1], P[2], mid);
            if (c == 0) return;
            P = {a, b, c};
        }
        type ^= 1;
    }
}

int32_t main() {

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 