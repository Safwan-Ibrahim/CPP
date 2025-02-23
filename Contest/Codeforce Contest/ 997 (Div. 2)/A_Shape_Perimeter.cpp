// Created on: 2025-01-17 20:44
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, m; cin >> n >> m;
    int a[n + 1], b[n + 1];
    int corx = 0, cory = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        a[i] += corx, b[i] += cory;
        corx = a[i], cory = b[i];
        //cout << a[i] << " " << b[i] << endl;
    }
    
    int left = n * m, right = left;
    for (int i = 2; i <= n; i++) {
        left -= m - (a[i] - a[i - 1]);
        right -= m - (b[i] - b[i - 1]);
    }

    cout << 2 * (left + right) << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 