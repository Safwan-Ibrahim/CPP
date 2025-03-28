// Created on: 2025-03-28 07:07
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1008, M = 1e9 + 7;
int n, Ans[N][N];
char A[N][N];

int total_path(int i, int j) {
    if (A[i][j] == '*') {
        return 0;
    }
    if (i == n && j == n) {
        return 1;
    }
    int &ans = Ans[i][j];
    if (ans != -1) {
        return ans;
    }
    ans = 0;
    if (i + 1 <= n) {
        ans += total_path(i + 1, j); ans %= M;
    }
    if (j + 1 <= n) {
        ans += total_path(i, j + 1); ans %= M;
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }
    
    memset(Ans, -1, sizeof Ans);
    cout << total_path(1, 1) << endl;
    return 0;
} 