// Created on: 2025-04-19 17:55
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8;
ll n, A[nn];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    sort(A + 1, A + n + 1);
    ll mn = A[1], gc = 0;
    for (int i = 2; i <= n; i++) {
        if (A[i] % mn == 0) {
            gc = __gcd(gc, A[i] / mn);
        }
    }

    cout << (gc == 1? "Yes\n" : "No\n");
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 