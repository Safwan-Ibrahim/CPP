// Created on: 2025-07-05 20:19
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    ll d = 1e18;
    for (int i = 63; i >= 0; i--) {
        if ((d >> i) & 1) {
            cout << i << " ";
        }
    }
    
    return 0;
} 