// Created on: 2025-07-09 15:53
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool p(int x) {
    int rt = sqrt(x); 
    return rt * rt != x;
}

void Try() {
    int n; cin >> n;
    vector<int>A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    bool yes = false;
    for (int i = 0; i < n; i++) {
        yes |= p(A[i]);
    }
    cout << (yes ? "YES\n" : "NO\n");
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 