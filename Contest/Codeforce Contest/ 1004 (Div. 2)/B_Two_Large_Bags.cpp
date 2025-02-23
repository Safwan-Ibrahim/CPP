// Created on: 2025-02-11 21:19
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    int Mp[1005];
    memset(Mp, 0, sizeof(Mp));
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        Mp[x]++;
    }

    int ex = 0;
    for (int i = 1; i <= 1000; i++) {
        Mp[i] += ex;
        if (Mp[i] > 2) {
            ex = Mp[i] - 2;
            Mp[i] = 2; 
        }
        else {
            ex = 0;
        }
    }

    for (int i = 1; i <= 1000; i++) {
        if (Mp[i] % 2 != 0) {
            cout << "No\n";
            return;
        }
    }
    
    cout << "Yes\n";
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 