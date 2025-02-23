// Created on: 2025-02-20 05:49
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    int A[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    ll sum = -n;
    for (int i = 1; i <= n; i++) {
        sum += A[i];
    }

    cout << sum << endl;
    
    return 0;
} 