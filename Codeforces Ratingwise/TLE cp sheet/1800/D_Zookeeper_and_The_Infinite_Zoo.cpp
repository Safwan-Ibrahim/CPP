// Created on: 2025-11-16 15:11
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int l, r; cin >> l >> r;
    
    int cnt = 0; bool pos = r >= l;
    for (int k = 0; k < 30 && pos; k++) {
        cnt -= r >> k & 1;
        cnt += l >> k & 1;
        if (cnt < 0) pos = 0;
    }

    cout << (pos ? "YES\n" : "NO\n");
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 