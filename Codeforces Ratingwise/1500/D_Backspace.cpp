// Created on: 2025-03-20 07:11
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    string S, T; cin >> S >> T;
    
    int ps = S.size() - 1, pt = T.size() - 1;
    for (int i = ps; i >= 0; i--) {
        if (pt >= 0 && S[i] == T[pt]) {
            pt--;
        }
        else {
            i--;
        }
    }
    
    if (pt == -1) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 