// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int x, y, n, m; 
    cin >> n >> m >> x >> y;
    
    for (int i = 1; i <= n; i++) {
        cin >> x;
    }
    for (int i = 1; i <= m; i++) {
        cin >> x;
    }
    
    cout << n + m << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 