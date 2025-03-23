// Created on: 2025-03-18 05:24
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 8, inf = 2e9 + 8;
int L[N], R[N], C[N];

void Try() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> L[i] >> R[i] >> C[i];
    }

    int mx = -1, mn = inf, cmx = inf, cmn = inf, c = inf;
    for (int i = 1; i <= n; i++) {
        if (mn == L[i]) {
            cmn = min(cmn, C[i]);
        }
        if (mx == R[i]) {
            cmx = min(cmx, C[i]);
        }
        if (mn > L[i]) {
            mn = L[i];
            cmn = C[i];
            c = inf;
        }
        if (mx < R[i]) {
            mx = R[i];
            cmx = C[i];
            c = inf;
        }
        if (mn == L[i] && mx == R[i]) {
            c = min(c, C[i]);
        }
        cout << min(c, cmx + cmn) << endl;
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