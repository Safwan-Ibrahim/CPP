// Created on: 2025-07-05 21:46
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define endl '\n'

ll n, l, r, k;

void Try() {
    cin >> n >> l >> r >> k; 
    ll mn = l;
    if (n == 2) {
        cout << -1 << endl; return;
    }
    if (n & 1) {
        cout << l << endl; return;
    }
    ll msb = 0;
    for (int i = 62; i >= 0; i--) {
        int b = (l >> i) & 1;
        if (b) {
            msb = i; break;
        }
    }
    for (int i = 62; i >= 0; i--) {
        int b1 = (r >> i) & 1;
        int b2 = (l >> i) & 1;
        if (b1 == b2) {
            if (b1 == 1) {
                cout << -1 << endl; return;
            }
        }
        else break;
    }

    msb++;
    ll mx = (1ULL << msb);
    if (mx > r) {
        cout << -1 << endl; return;
    }
    if (k == n || k + 1 == n) {
        cout << mx << endl;
    }
    else cout << mn << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 