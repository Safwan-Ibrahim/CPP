// Created on: 2025-02-19 01:18
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int power(int x, int n, int m) {
    int ans = 1 % m;
    while(n > 0) {
        if (n & 1) {
            ans = 1LL * ans * x % m;
        }
        n >>= 1;
        x = 1LL * x * x % m;
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cout << 998244353 + 1 << endl;
    
    return 0;
} 