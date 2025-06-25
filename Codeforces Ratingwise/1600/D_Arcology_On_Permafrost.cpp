// Created on: 2025-06-06 00:27
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 18;
int pn, tn, k, A[nn];

void Try() {
    cin >> pn >> tn >> k;
    for (int i = 1; i <= pn; i++) {
        cout << (i - 1) % (pn - tn * k <= pn / (tn + 1) ? k : pn / (tn + 1)) << " ";
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