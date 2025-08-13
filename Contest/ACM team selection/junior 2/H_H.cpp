// Created on: 2025-08-01 15:07
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
    int ans = n - b + 1 + d + (c - a - 1) * (n + 1);
    cout << ans << endl;
    return 0;
} 