// Created on: 2025-07-12 02:44
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn];

void Try() {
    cin >> n; n *= 2;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    sort(A + 1, A + n + 1);
    cout << A[n / 2 + 1] - A[n / 2] << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 