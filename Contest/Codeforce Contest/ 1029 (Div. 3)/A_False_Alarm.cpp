// Created on: 2025-06-08 20:37
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, t; cin >> n >> t;
    int first = -1, last = -1;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        if (c == '1') {
            if (first == -1) first = i;
            last = i;
        }
    }

    if (first == -1 || last - first + 1 <= t) cout << "YES\n";
    else cout << "NO\n"; 
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 