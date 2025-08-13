// Created on: 2025-07-28 18:15
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n; char A[2][nn];
int Ans[2][2][2][2][nn];

int way(int row, int col, bool self, bool down, bool front) {
    if (col == n + 1) return 1;
    int &ans = Ans[front][down][self][row][col];
    if (ans != -1) return ans;
    ans = 0;
    if (row == 0) {
        if (A[row][col] == '#' || self) {
            ans = way(row ^ 1, col, down, false, front);
        }
        else {  
            if (A[row][col + 1] == '.' && !front) {
                ans += way(row ^ 1, col, down, false, true); ans = min(ans, 2); 
            }
            if (A[row ^ 1][col] == '.' && !down) {
                ans += way(row ^ 1, col, true, false, false); ans = min(ans, 2);
            }
        }
    }
    else {
        if (A[row][col] == '#' || self) {
            ans = way(row ^ 1, col + 1, front, false, false);
        }
        else {
            if (A[row][col + 1] == '.') {
                ans = way(row ^ 1, col + 1, front, true, false);
            }
        }
    }
    return ans;
}

void Try() {
    cin >> n;
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    A[0][n + 1] = A[1][n + 1] = '#';  
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    for (int m = 0; m < 2; m++) {
                        Ans[j][k][l][m][i] = -1;
                    }
                }
            }
        }
    }
    int ans = way(0, 1, 0, 0, 0);
    if (ans == 0) {
        cout << "None\n";
    }
    else if (ans == 1) {
        cout << "Unique\n";
    }
    else cout << "Multiple\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 