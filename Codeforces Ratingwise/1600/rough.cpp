// Created on: 2025-06-11 04:39
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17, mod = 998244353; 
int n, A[nn];

int way() {
    vector<int>As_honest(n + 1, 0), As_liar(n + 1, 0);

    As_honest[0] = As_liar[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (A[i] == A[i - 1]) {
            As_honest[i] = As_honest[i - 1];
        }
        if (i > 1 && A[i] == A[i - 2] + 1) {
            As_honest[i] += As_liar[i - 1];
        }
        if (As_honest[i] >= mod) As_honest[i] -= mod;
        As_liar[i] = As_honest[i - 1];
    }

    return (As_honest[n] + As_liar[n]) % mod;
}

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    cout << way() << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }

    return 0;
} 