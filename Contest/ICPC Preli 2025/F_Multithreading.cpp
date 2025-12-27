// Created on: 2025-11-30 11:36
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int mn = n + 1, ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (A[i] > mn) ans++;
        mn = min(mn, A[i]);
    }

    cout << ans << endl;
    
    return 0;
} 