// Created on: 2025-02-09 20:49
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 9;
int A[N], B[N];

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> B[i];
    }

    int prev = INT_MIN;
    for (int i = 1; i <= n; i++) {
        int a = min(A[i], B[1] - A[i]), b = max(A[i], B[1] - A[i]);
        if (a >= prev) {
            A[i] = a;
            prev = a;
        }
        else {
            A[i] = b;
            prev = b;
        }
    }

    bool st = 1;
    for (int i = 1; i + 1 <= n; i++) {
        if (A[i] > A[i + 1]) {
            st = 0;
            break;
        }
    }

    if (st) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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