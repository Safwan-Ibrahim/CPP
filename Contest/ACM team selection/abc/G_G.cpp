// Created on: 2025-11-07 10:17
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;

    if (n == 2) {
        cout << -1 << endl; return;
    }
    
    vector<vector<char>> S(n, vector<char> (n,'0'));
    
    for (int i = 0; i < n; i++) {
        S[0][i] = '1';
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i; j++) {
            S[i][j] = '1';
        }
    }

    S[n - 1][1] = '0';

    for (auto s : S) {
        for (auto c : s) {
            cout << c;
        }
        cout << endl;
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