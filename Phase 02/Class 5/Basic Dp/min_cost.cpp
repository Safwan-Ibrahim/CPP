// Created on: 2025-03-22 04:01
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1005, inf = 2e9 + 8;
int n, m, A[N][N], Ans[N][N]; // do it now

int min_cost(int i, int j) {
    if (i > n || j > m) {
        return inf;
    }
    if (i == n && j == m) {
        return A[i][j];
    }
    if (Ans[i][j] != -1) {
        return Ans[i][j];
    }
    return Ans[i][j] = A[i][j] + min(min_cost(i + 1, j), min_cost(i, j + 1));
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
    }
    
    memset(Ans, -1, sizeof Ans);
    cout << min_cost(1, 1) << endl;
    return 0;
} 