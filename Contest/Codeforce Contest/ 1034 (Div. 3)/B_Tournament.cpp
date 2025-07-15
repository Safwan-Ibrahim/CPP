// Created on: 2025-07-01 20:44
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, id, k; cin >> n >> id >> k;
    int A[n + 1];
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        mx = max(mx, A[i]);
    }
    
    if (k == 1 && mx > A[id]) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 