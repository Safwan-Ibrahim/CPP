// Created on: 2025-05-26 23:46
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int x, y, d; cin >> x >> y >> d;
    
    int t = sqrt(x * x + y * y);

    if (t <= d) {
        cout << "yes\n";
    }
    else {
        cout << "no\n";
    }
    
    return 0;
} 