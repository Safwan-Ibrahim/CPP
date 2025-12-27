// Created on: 2025-11-28 20:46
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;

    ll cut = 0, v = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        cut += max(0, x - 1);
        if (x) v++;
    }
    
    ll left = n - cut;
    if (cut >= n - 1) {
        cout << v << endl;
    } 
    else {
        cout << max(1LL, v - left + 1) << endl;
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 