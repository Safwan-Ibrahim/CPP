// Created on: 2025-01-30 19:08
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 3e5 + 9;
int A[N], n;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    if (n % 2 == 0) {
        cout << "YES\n";
        return;
    }

    int mx = -1;
    for (int i = 1; i <= n; i++) {
        if (A[i] <= mx) {
            cout << "YES\n";
            return;
        }
        mx = max(A[i], mx);
    }

    cout << "NO\n";
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 