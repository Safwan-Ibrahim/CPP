// Created on: 2025-06-16 12:16
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define int long long

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int ans; cin >> ans;
    return ans;
}

void Try() {
    int n; cin >> n;
    bool imp = true;
    int i;
    for (i = 1; i + 1 <= n; i++) {
        int ans = query(i, i + 1);
        if (ans) {
            imp = false; break;
        }
    }

    if (imp) {
        cout << "! IMPOSSIBLE" << endl; return;
    }
    vector<char> S(n + 1, '1');
    int ans = 1;
    if (i > 1) {
        ans = query(1, i + 1);
    }
    for (int j = i, k = 1; k <= ans; j--, k++) {
        S[j] = '0';
    }
    int prev = 1;
    for (int k = 2; i + k <= n; k++) {
        int ans = query(i, i + k);
        if (ans == prev) S[i + k] = '0';
        else S[i + k] = '1';
        prev = ans;
    }

    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << S[i];
    }
    cout << endl;
}

int32_t main() {
    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 