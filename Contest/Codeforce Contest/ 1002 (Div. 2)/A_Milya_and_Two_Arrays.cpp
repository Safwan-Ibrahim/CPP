// Created on: 2025-02-02 20:52
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    set<int>A, B;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        A.insert(x);
    }
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        B.insert(x);
    }
    
    int a = A.size(), b = B.size();
    if (min(a, b) == 1 && max(a, b) <= 2) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 