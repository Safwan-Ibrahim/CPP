// Created on: 2025-06-20 22:11
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, m; cin >> n >> m;
    int A[n + 5][m + 5], B[n + 5][m + 5];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
    }

    vector<int>Row_location(n * m + 10), Col_location(n * m + 10);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> B[i][j];
            Row_location[B[i][j]] = i;
            Col_location[B[i][j]] = j;
        }
    }

    vector<int> For_row[n + 1];
    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= m; col++) {
            For_row[row].push_back(B[row][col]);
        }
        sort(For_row[row].begin(), For_row[row].end());
    }

    bool yes = true;
    for (int row = 1; row <= n; row++) {
        vector<int>V;
        for (int col = 1; col <= m; col++) {
            V.push_back(A[row][col]);
        }
        sort(V.begin(), V.end());
        if (For_row[Row_location[V.front()]] != V) yes = false;
    }
    
    vector<int> For_col[m + 1];
    for (int col = 1; col <= m; col++) {
        for (int row = 1; row <= n; row++) {
            For_col[col].push_back(B[row][col]);
        }
        sort(For_col[col].begin(), For_col[col].end());
    }
    
    for (int col = 1; col <= m; col++) {
        vector<int>V;
        for (int row = 1; row <= n; row++) {
            V.push_back(A[row][col]);
        }
        sort(V.begin(), V.end());
        if (For_col[Col_location[V.front()]] != V) yes = false;
    }

    cout << (yes ? "YES\n" : "NO\n");

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 