// Created on: 2025-01-03 22:12
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll l, r; cin >> l >> r; 
    cout << "YES\n";
    for (ll i = l; i <= r; i += 2) {
        cout << i << " " << i + 1 << endl;
    }
    
    return 0;
} 