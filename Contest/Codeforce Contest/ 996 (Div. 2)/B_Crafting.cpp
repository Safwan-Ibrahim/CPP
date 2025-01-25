// Created on: 2025-01-16 10:12
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    int a[n + 1], b[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }    
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    int loss = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] < b[i]) {
            loss = (b[i] - a[i]);
            a[i] += 2 * loss;  
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        if(a[i] - loss < b[i]) {
            cout << "NO\n";     
            return;
        }
    }

    cout << "YES\n";
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}   