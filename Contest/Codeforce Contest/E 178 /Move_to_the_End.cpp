// Created on: 2025-04-28 20:49
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, A[nn], Mx[nn];
ll Suf[nn];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    int mx = -1;
    Mx[0] = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, A[i]);
        Mx[i] = mx;
    }

    ll sum = 0;
    for (int i = n; i >= 1; i--) {
        sum += A[i];
        Suf[i] = sum;
    }

    Suf[n + 1] = 0;
    for (int i = 1; i <= n; i++) {
        int j = n - i + 2;
        cout << Suf[j] + Mx[j - 1] << " ";
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