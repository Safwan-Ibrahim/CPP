// Created on: 2025-05-04 21:39
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8;
int n, Up[nn], Max_take[nn];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> Up[i];
    }

    int mx = -1;
    for (int i = n; i >= 1; i--) {
        Max_take[i] = 1;
        for (int j = i + i; j <= n; j += i) {
            if (Up[j] > Up[i]) {
                Max_take[i] = max(1 + Max_take[j], Max_take[i]);
            }
        }
        mx = max(Max_take[i], mx);
    }
    
    cout << mx << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 