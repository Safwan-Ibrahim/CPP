// Created on: 2025-05-14 21:36
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int mx = -1; ll sum = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        mx = max(mx, x);
        sum += x;
    }
    
    sum -= mx;
    if (sum >= mx && mx % 2 == sum % 2) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
    
    return 0;
} 