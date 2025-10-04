// Created on: 2025-08-28 08:50
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;

    int cnt = 0;
    int mx = (1 << (31 - __builtin_clz(n - 1) + 1)) - 1;
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            if ((j ^ i) == mx || (j | i) == mx) {
                cout << i << " " << j << " " << (j | i) << " " << (j ^ i) << endl;
                cnt++;
            }
        }
    }

    cerr << cnt << endl;
    
    return 0;
} 