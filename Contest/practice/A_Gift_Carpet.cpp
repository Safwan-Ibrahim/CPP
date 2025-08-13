// Created on: 2025-08-06 21:16
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 25;
int n, m; char S[nn][nn];

void Try() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> S[i][j];
        }
    }
    
    string T = "vika";
    int p = 0;
    for (int col = 1; col <= m; col++) {
        for (int row = 1; row <= n; row++) {
            if (S[row][col] == T[p]) {
                p++; break;
            }
        }
    }    

    cout << (p == 4 ? "YES\n" : "NO\n");
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 