// Created on: 2025-02-26 11:44
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
    if (b % a > e % d) {
        cout << "Alice\n";
    }
    else if (b % a < e % d) {
        cout << "Bob\n";
    }
    else {
        cout << "Draw\n";
    }
    
    
    return 0;
} 