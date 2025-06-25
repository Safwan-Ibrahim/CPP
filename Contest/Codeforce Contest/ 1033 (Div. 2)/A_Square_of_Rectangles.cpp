// Created on: 2025-06-21 20:41
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    vector<int>L(3), R(3);
    for (int i = 0; i < 3; i++) {
        cin >> L[i] >> R[i];
    }
    
    if (accumulate(L.begin(), L.end(), 0) == R[0] && R[0] == R[2] || (accumulate(R.begin(), R.end(), 0) == L[0] && L[0] == L[2])) {
        cout << "YES\n"; return;
    }
    
    if (L[0] == L[1] + L[2] && R[1] == R[2] && R[0] + R[1] == L[0]) {
        cout << "YES\n"; return;
    }
    swap(L, R);
    if (L[0] == L[1] + L[2] && R[1] == R[2] && R[0] + R[1] == L[0]) {
        cout << "YES\n"; return;
    }

    cout << "NO\n";
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 