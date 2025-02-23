// Created on: 2025-02-09 22:14
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void Try() {
    int n, m; cin >> n >> m;
    
    int A[n + 5][m + 5];
    set<pair<int, int>>St;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
            sum += A[i][j];
        }
        St.insert({sum, i});
    }

    vector<int>B;
    for (auto it = St.rbegin(); it != St.rend(); it++) {
        int y = it->second;
        for (int i = 1; i <= m; i++) {
            B.push_back(A[y][i]);
        }
    }

    int sum = 0;
    int ml = n * m;
    for (auto x : B) {
        sum += x * ml--;
    }

    cout  << sum << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 