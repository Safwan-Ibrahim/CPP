// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 250000 + 1000;
int n, q, A[nn], Cost[nn], E[nn], Ewf[nn];

bool pos(int x) {
    if ((x & (x - 1)) == 0) return false;
    return true;
}

void Try() {
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    int cost = 0;
    for (int i = 1; i <= n; i++) {
        cost += __lg(A[i]);
        Cost[i] = cost;
        E[i] = pos(A[i]);
        Ewf[i] = pos(A[i] >> 1);
    }

    int e = 0, ewf = 0;
    for (int i = 1; i <= n; i++) {
        e += E[i];
        ewf += Ewf[i];
        E[i] = e, Ewf[i] = ewf;
    }

    while (q--) {
        int l, r; cin >> l >> r;
        cost = Cost[r] - Cost[l - 1] + E[r] - E[l - 1];
        int cut = (E[r] - E[l - 1] - (Ewf[r] - Ewf[l - 1]) + 1) / 2;
        cout << cost - cut << endl;
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