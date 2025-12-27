// Created on: 2025-11-27 20:44
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, m; cin >> n >> m;

    vector<string> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    vector<vector<string>> B(m, vector<string> (n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }
    
    bool pos = true;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < m; j++) {
            if (A[i] == B[j][i]) {
                found = true; break;
            }
        }
        if (!found) {
            pos = false; break;
        }
    }

    if (!pos) {
        cout << -1 << endl; return;
    }

    int mn = 1e9;
    for (int i = 0; i < m; i++) {
        int mx = 0;
        for (int j = 0; j < n; j++) {
            if (B[i][j] == A[j]) mx++;
        }

        mn = min(mn, mx + (n - mx) * 3);
    }

    cout << mn << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 