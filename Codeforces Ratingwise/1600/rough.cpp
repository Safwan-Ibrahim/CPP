// Created on: 2025-06-20 14:17
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int ds(int x) {
    int ans = 0;
    while(x) {
        ans += x / 10;
        x /= 10;
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int k; cin >> k;
    for (int i = 100; i <= 100000; i++) {
        if (ds(k * i) == ds(i) * k) cout << i << endl;
    }   
        
    return 0;
} 