// Created on: 2025-02-09 20:49
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N = 2e5 + 9;
int A[N], B[N];

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    set<int>St;
    for (int i = 1; i <= m; i++) {
        cin >> B[i];
        St.insert(B[i]);
    }

    int prev = INT_MIN;
    for (int i = 1; i <= n; i++) {
        int need = prev + A[i];
        auto value = St.lower_bound(need);
        int mn = A[i], mx = A[i];
        if (value != St.end()) {
            mn = min(A[i], *value - A[i]), mx = max(A[i], *value - A[i]);
        }
        if (mn >= prev) {
            A[i] = mn;
            prev = mn;
        }
        else {
            A[i] = mx;
            prev = mx;
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