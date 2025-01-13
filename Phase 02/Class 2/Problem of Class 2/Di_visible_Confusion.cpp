// Created on: 2025-01-11 08:20
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int rp = 0; // reducing power
    for (int i = 1; i <= n; i++) {

        bool cant = true;
        for (int j = i + 1; j >= i + 1 - rp; j--) {
            if (a[i] % j != 0) {
                rp++;
                cant = false; break;
            } 
        }
        if (cant) {
            cout << "NO\n"; return;
        }
    }
    cout << "YES\n";

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 