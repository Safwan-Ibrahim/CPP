// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;

    int A[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    sort(A + 1, A + n + 1);
    int mn = -1e9;
    for (int i = 2; i <= n; i += 2) {
        mn = max(mn, A[i] - A[i - 1]);
    }

    cout << mn << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 