// Created on: 2025-05-26 23:35
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int x, y; cin >> x >> y;
    cout << x << " " << y << " " ;
    
    double d = sqrt(x * x + y * y) - 3;
    cout << (int) d << endl; 
    
    return 0;
} 