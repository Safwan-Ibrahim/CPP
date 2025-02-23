// Created on: 2025-02-16 17:21
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 9;
int A[N];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    int mn = 2e9, id;
    for (int i = 2; i <= n; i++) {
        if (A[i] <= mn) {
            mn = A[i];
            id = i;
        }
    }


    mn = min(A[1], A[id]);
    cout << n << endl << 1 << " " << id << " " << min(A[1], A[id]) << " " << max(A[1], A[id]) << endl;
    for (int i = 2; i <= n; i++) {
        cout << 1 << " " << i << " " << mn << " " << mn + i - 1 << endl;
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