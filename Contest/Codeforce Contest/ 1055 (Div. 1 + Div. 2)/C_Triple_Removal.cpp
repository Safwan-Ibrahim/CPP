// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 250000 + 1000;
int n, q, Po[nn], Pz[nn], Pc[nn], A[nn];

void Try() {
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    int o = 0, z = 0, c = 0;
    for (int i = 1; i <= n; i++) {
        o += A[i] == 1;
        z += A[i] == 0;
        c += A[i - 1] == A[i];
        Po[i] = o, Pz[i] = z, Pc[i] = c;
    }
    
    while(q--) {
        int l, r; cin >> l >> r;
        o = Po[r] - Po[l - 1];
        z = Pz[r] - Pz[l - 1];
        c = Pc[r] - Pc[l];
        if (o % 3 != 0 || z % 3 != 0) {
            cout << -1 << endl;
        }
        else {
            cout << (r - l + 1) / 3 + (c == 0) << endl;
        }
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    A[0] = -1;
    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 