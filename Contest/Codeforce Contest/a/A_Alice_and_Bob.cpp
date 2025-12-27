// Created on: 2025-11-14 20:39
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, a; cin >> n >> a;
    vector<int> A(n);
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int x = 0, y = 0, b1 = a - 1, b2 = a + 1;
    for (int i = 0; i < n; i++) {
        if (A[i] <= b1) {
            x++;
        }
        if (A[i] >= b2) {
            y++;
        }
    }

    if (y > x) swap(b1, b2);

    cout << b1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 