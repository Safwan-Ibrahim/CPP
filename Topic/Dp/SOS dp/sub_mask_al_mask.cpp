// Created on: 2025-11-15 12:42
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n = 20;
    for (int m=0; m<(1<<n); ++m) {
        for (int s=m; s; s=(s-1)&m) {
            cout << s << " ";
        }
    }
    return 0;
} 