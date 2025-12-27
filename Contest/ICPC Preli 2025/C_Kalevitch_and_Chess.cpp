// Created on: 2025-11-30 09:10
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    vector<string> A(8);
    for (int i = 0; i < 8; i++) {
        cin >> A[i];
    }
    
    bool eq = 1;
    for (int i = 1; i < 8; i++) {
        if (A[i] != A[0]) eq = 0;
    }

    if (eq) {
        cout << (A[0][0] == 'W' ? 0 : 8) << endl; return 0;
    }

    int ans = 0;
    for (int i = 0; i < 8; i++) {
        int c = count(A[i].begin(), A[i].end(), 'B');
        if (c == 8) ans++;
    }
    
    for (int i = 0; i < 8; i++) {
        string T = "";
        for (int j = 0; j < 8; j++) {
            T += A[j][i];
        }
        int c = count(T.begin(), T.end(), 'B');
        if (c == 8) ans++;
    }

    cout << ans << endl;

    return 0;
} 