// Created on: 2025-01-19 22:00
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i + 1 <= n; i++) {
        if (a[i + 1] < a[i]) {
            cout << "NO\n"; 
            return;
        }
        else {
            a[i + 1] -= a[i];
        }
    }
    
    cout << "YES\n";
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 