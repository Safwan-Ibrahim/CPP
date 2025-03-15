// Created on: 2025-02-26 11:49
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int ans = n;
    int ex = 0;
    int r = 0;

    while(n > 1) {
        if (n & 1) {
            r = 1;
        }
        ans += n / 2;
        n /= 2;
        if (r) {
            n++;
            r = 0; 
        }
    }
    cout << ans << endl;
    
    return 0;
} 