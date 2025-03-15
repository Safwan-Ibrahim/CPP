// Created on: 2025-02-24 10:02
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

    ll odd = 0, even = 0;
    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            odd += A[i];
        }
        else {
            even += A[i];
        }
    }

    bool one = even > odd;
    for (int i = 1; i <= n; i++) {
        cout << (one ? 1 : A[i]) << " ";
        one ^= 1;
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 