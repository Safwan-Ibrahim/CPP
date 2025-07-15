// Created on: 2025-07-13 19:36
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    vector<int>A(n);
    for (auto &x : A) {
        cin >> x;
    }

    int mn = 100, mx = -1;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
    }

    if (is_sorted(A.begin(), A.end()) || mn == 0 && mx == 1) {
        cout << "Yes\n"; 
    }
    else cout << "No\n";
   
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 