// Created on: 2025-04-19 22:15
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    int A[n + 2][n + 2];    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    set<int>St;
    map<int, set<int>>Cs;
    for (int col = 1; col <= n; col++) {
        map<int, vector<int>>Mp;
        for (int row = 1; row <= n; row++) {
            int v = A[row][col];
            Mp[v].push_back(row);
            Cs[col].insert(v);
        }
        for (auto [x, y] : Mp) {
            if (y.size() > 1) {
                for (auto v : y) {
                    St.insert(v);
                }
            }
        }
    }  

    for (auto i : St) {

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