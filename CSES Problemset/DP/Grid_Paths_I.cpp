// Created on: 2025-07-08 14:31
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1007, mod = 1e9 + 7;
int n; char S[nn][nn];

int dp() {
    // from i, j to right n, m is Way[i][j]
    vector<vector<int>>Way(n + 2, vector<int>(n + 2, 0));
    for (int row = n; row >= 1; row--) {
        for (int col = n; col >= 1; col--) {
            if (S[row][col] == '*') {
                continue;
            }
            else if (row == n && col == n) {
                Way[row][col] = 1;
            }
            else {
                Way[row][col] = Way[row][col + 1];
                Way[row][col] += Way[row + 1][col];
                Way[row][col] %= mod;
            }
        }
    }
    return Way[1][1];
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> S[i][j];
        }
    }
    
    cout << dp() << endl;
    
    return 0;
} 