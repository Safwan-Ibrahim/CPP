// Created on: 2025-02-02 21:44
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n, k; cin >> n >> k;
    int A[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    if (k == n) {
        int sq = 1;
        for (int i = 2; i <= n; i += 2) {
            if (A[i] != sq) {
                break;
            }
            else {
                sq++;
            }
        }
        cout << sq << endl;
    }
    else {
        for (int i = 2; i <= n - k + 2; i++) {
            if (A[i] != 1) {
                cout << 1 << endl;
                return;
            }
        }
        cout << 2 << endl;
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 