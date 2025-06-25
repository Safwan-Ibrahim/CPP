// Created on: 2025-06-23 20:46
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    int A[n + 2];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    int ans = 1e9;
    for (int i = 1; i + 1 <= n; i++) {
        if (abs(A[i] - A[i + 1]) <= 1) ans = 0;
        if (i + 2 <= n) {
            if (A[i + 1] <= A[i] && A[i + 2] >= A[i] || A[i + 1] >= A[i] && A[i + 2] <= A[i]) ans = min(ans, 1);
            swap(A[i], A[i + 2]);
            if (A[i + 1] <= A[i] && A[i + 2] >= A[i] || A[i + 1] >= A[i] && A[i + 2] <= A[i]) ans = min(ans, 1);
            swap(A[i], A[i + 2]);
        }
    }

    if (ans == 1e9) {
        cout << -1 << endl;
    }
    else cout << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 