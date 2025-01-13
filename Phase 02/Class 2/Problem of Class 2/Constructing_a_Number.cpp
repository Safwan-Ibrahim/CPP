// Created on: 2025-01-06 20:57
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int digit_sum(int x) {
    int sum = 0;
    while(x > 0) {      
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

void solve() {
    int n; cin >> n;

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        sum += digit_sum(x);
    }  
    
    if (sum % 3) {
        cout << "No\n";
    }
    else {
        cout << "Yes\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 