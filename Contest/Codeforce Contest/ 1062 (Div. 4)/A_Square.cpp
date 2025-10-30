// Created on: 2025-10-28 20:35
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    set<int> St;

    for (int i= 1; i <= 4; i++) {
        int x; cin >> x;
        St.insert(x);
    }
    
    cout << (St.size() == 1 ? "YES\n" : "NO\n");
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 