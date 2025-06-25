// Created on: 2025-05-27 00:01
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    int sum = 0;
    bool z = false;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        sum += x;
        z |= x == 0;
    }
    
    cout << sum + z << endl;
    
    return 0;
} 