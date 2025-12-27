// Created on: 2025-05-30 00:19
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, m; cin >> n >> m;
    ll A[n + 3];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    sort(A + 1, A + n + 1);
    ll mn = A[1], gcd_dif = 0;
    for (int i = 2; i <= n; i++) {
        gcd_dif = gcd(gcd_dif, A[i] - mn);
    }
    
    for (int i = 1; i <= m; i++) {
        ll x; cin >> x;
        cout << gcd(mn + x, gcd_dif) << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; 
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 