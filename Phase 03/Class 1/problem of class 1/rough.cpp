// Created on: 2025-07-09 17:03
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n = 9;
    for (int i = 1; i <= 15; i++) {
        n = n * 10 + 9;
        cout << (n - 1) % 8 << endl;
    }
    
    
    return 0;
} 