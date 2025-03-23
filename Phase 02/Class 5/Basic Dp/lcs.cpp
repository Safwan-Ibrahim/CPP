// Created on: 2025-03-22 21:19
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 3008;
string S, T;
int Dp[N][N];

int lcs(int i, int j) {
    if (i >= S.size() || j >= T.size()) {
        return 0;
    }
    if (Dp[i][j] != -1) {
        return Dp[i][j];
    }
    int ans = lcs(i + 1, j);
    ans = max(ans, lcs(i, j + 1));
    if (S[i] == T[j]) {
        ans = max(ans, lcs(i + 1, j + 1) + 1);
    }
    return Dp[i][j] = ans;
}

void path(int i, int j) {
    if (i >= S.size() || j >= T.size()) {
        return;
    }
    if (S[i] == T[j]) {
        cout << S[i];
        path(i + 1, j + 1);
        return;
    }
    int l = lcs(i + 1, j);
    int r = lcs(i, j + 1);
    if (l >= r) {
        path(i + 1, j);
    }
    else {
        path(i, j + 1);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> S >> T;
    memset(Dp, -1, sizeof Dp);
    //lcs(0, 0);
    path(0, 0);
    cout << endl;
    return 0;
} 