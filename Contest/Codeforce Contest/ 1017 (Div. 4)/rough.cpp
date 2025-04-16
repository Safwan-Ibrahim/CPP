// Created on: 2025-04-14 00:18
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

    vector<int>Bit(30, 0);
    for (int i = 1; i <= n; i++) {
        int v = A[i];
        for (int k = 0; k < 30; k++) {
            int bit = (v >> k) & 1;
            if (bit == 1) {
                Bit[k]++;
            }
        }
    }

    ll sum = 0;
    for (int k = 0; k < 30; k++) {
        sum += 1LL * Bit[k] * (1 << k);
    }

    cout << sum << endl;
        
    return 0;
} 