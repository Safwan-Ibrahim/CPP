// Created on: 2025-05-26 23:26
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n; cin >> n; 
    int mx = -1, sum = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        mx = max(x, mx);
        sum += x;
    }

    cout << sum - (mx - 1) << endl;
    
    return 0;
} 