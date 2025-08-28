// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
ll n, k, A[nn], M[nn];

void Try() {
    cin >> n >> k; k++;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        M[i] = A[i] % k;
    }

    ll g = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] % k != 0) {
            A[i] += M[i] * (k - 1);
        }
        g = gcd(g, A[i]);
    }
    assert(g > 1);

    for (int i = 1; i <= n; i++) {
        cout << A[i] << " ";
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