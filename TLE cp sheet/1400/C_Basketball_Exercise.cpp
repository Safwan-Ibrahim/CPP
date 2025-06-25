// Created on: 2025-05-05 04:13
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8;
int n, Up[nn], Down[nn];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> Up[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> Down[i];
    }

    vector<ll>Mx_up(n + 5, 0), Mx_down(n + 5, 0);
    for (int i = n; i >= 1; i--) {
        Mx_up[i] = max(Up[i] + Mx_down[i + 1], Up[i] + Mx_down[i + 2]);
        Mx_down[i] = max(Down[i] + Mx_up[i + 1], Down[i] + Mx_up[i + 2]);
    }

    cout << max(Mx_down[1], Mx_up[1]) << endl;
    
    return 0;
} 