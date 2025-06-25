// Created on: 2025-06-08 22:39
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    int A[n + 5], B[n + 5];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }
    
    map<int, int>IA, IB;
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        if (A[i] == B[i] || IB[A[i]] > i + 1 || IA[B[i]] > i + 1 || IB[B[i]] != 0 || IA[A[i]] != 0) {
            ans = i; break;
        }
        if (IB[B[i]] == 0) {
            IB[B[i]] = i;
        }
        if (IA[A[i]] == 0) {
            IA[A[i]] = i;
        }
    }

    cout << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 