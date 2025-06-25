// Created on: 2025-04-21 03:53
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e3 + 8, mod = 1e9 + 7;
int C[nn][nn];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    C[0][0] = 1;
    for (int i = 1; i < nn; i++) {
        C[i][0] = 1;
        for (int k = 1; k <= i; k++) {
            C[i][k] = (C[i - 1][k - 1] + C[i - 1][k]) % mod;
        }    
    }
    
    
    
    return 0;
} 