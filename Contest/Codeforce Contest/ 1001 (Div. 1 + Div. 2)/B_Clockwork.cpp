// Created on: 2025-01-26 21:08
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 5e5 + 9;
int A[N];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++) {
        if (A[i] - (n - i) * 2 <= 0 || A[i] - (i - 1) * 2 <= 0) {
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