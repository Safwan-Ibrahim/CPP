// Created on: 2025-08-01 10:41
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1000 + 17;
int n, m; char A[nn][nn];
bool Vs[nn][nn];

void check(vector<tuple<char, int, int>> &V) {
    for (auto [c, row, col] : V) {
        if (c != '.') break;
        Vs[row][col] = true;
    }
    reverse(V.begin(), V.end());
    for (auto [c, row, col] : V) {
        if (c != '.') break;
        Vs[row][col] = true;
    }
} 

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
    }
    
    for (int row = 1; row <= n; row++) {
        vector<tuple<char, int, int>>V;
        for (int col = 1; col <= m; col++) {
            V.push_back({A[row][col], row, col});
        }
        check(V);
    }
    
    for (int col = 1; col <= m; col++) {
        vector<tuple<char, int, int>>V;
        for (int row = 1; row <= n; row++) {
            V.push_back({A[row][col], row, col});
        }
        check(V);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans += Vs[i][j];
        }
    }

    cout << ans << endl;

    return 0;
} 