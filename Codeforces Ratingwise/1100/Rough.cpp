// Created on: 2025-01-22 14:46
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int rt(int x) {
    int lo = 1, hi = x;
    int ans = 1;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if (1LL * mid * mid > x) {
            hi = mid - 1;
        }
        else if (1LL * mid * mid <= x) {
            ans = mid;
            lo = mid + 1;
        }
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int X; cin >> X;
    cout << rt(X) << endl;
    cout << int (sqrt(X)) << endl;
    
    return 0;
} 