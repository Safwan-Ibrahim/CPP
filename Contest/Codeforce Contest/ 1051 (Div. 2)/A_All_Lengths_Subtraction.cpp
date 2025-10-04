// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    int l, r, A[n + 1];
    
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (A[i] == n) l = i, r = i;
    }
    
    for (int i = n - 1; i >= 1; i--) {
        if (A[max(1, l - 1)] == i) {
            l--;
        }
        else if (A[min(n, r + 1)] == i) {
            r++;
        }
        else {
            cout << "NO\n"; return;
        }
    }

    cout << "YES\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 