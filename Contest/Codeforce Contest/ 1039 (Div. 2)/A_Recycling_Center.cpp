// Created on: 2025-07-27 20:38
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, c; cin >> n >> c;
    vector<ll>V(n);
    for (int i = 0; i < n; i++) {
        cin >> V[i];
    }
    
    int ans = 0, p = 0;
    sort(V.rbegin(), V.rend());
    for (int i = 0; i < n; i++) {
        if (V[i] * (1LL << p) > c) ans++;
        else p++;
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 