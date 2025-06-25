// Created on: 2025-05-13 15:54
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8;
int n, A[nn];

int msb(int x) {
    return 31 - __builtin_clz(x);
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    int mx = -1;
    for (int i = 2; i <= n; i++) {
        if (A[i] < A[i - 1]) {
            mx = max(mx, msb(A[i - 1] - A[i]));
            A[i] = A[i - 1];
        }
    }
    cout << mx + 1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 