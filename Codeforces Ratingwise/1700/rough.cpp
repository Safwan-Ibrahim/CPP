// Created on: 2025-07-31 09:24
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    int A[n + 1];
    iota(A + 1, A + n + 1, 1);
    rotate(A + 1, A + n / 2 + 1, A + n + 1);
    for (int i = 1; i <= n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
} 