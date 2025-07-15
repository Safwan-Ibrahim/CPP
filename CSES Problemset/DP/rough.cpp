// Created on: 2025-07-07 22:56
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool is_pow(int x, int n) {
    int v = x;
    while(v < n && 1LL * v * x <= 1e9) {
        v *= x;
    }
    return v == n;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    int val; cin >> val;
    for (int i = 2; i <= n; i++) {
        if (is_pow(i, val)) {
            cout << i << endl;
        }
    }
    
    return 0;
} 