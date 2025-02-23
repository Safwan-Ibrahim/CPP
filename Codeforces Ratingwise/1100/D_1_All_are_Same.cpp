// Created on: 2025-01-30 18:12
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 105;
int A[N], n;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 2e6 + 1; i >= 1; i--) {
        bool eq = true;
        int the_num = ((A[1] % i) + i) % i;
        for (int j = 2; j <= n; j++) {
            if (((A[j] % i) + i) % i != the_num) {
                eq = false;
                break;
            }
        }
        if (eq) {
            if (i > 2e6) {
                cout << -1 << endl;
            }
            else {
                cout << i << endl;
            }
            return;
        }
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