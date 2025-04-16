// Created on: 2025-04-16 03:03
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n, q; cin >> n >> q;
    int A[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    memset(A, 0, sizeof A);

    while(q--) {
        int l, r, x; cin >> l >> r >> x;
        A[l] += x, A[r + 1] -= x;
    }

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += A[i];
        A[i] = sum;
    }

    return 0;
} 