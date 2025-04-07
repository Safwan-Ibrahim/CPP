// Created on: 2025-03-28 20:08
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

string S, T, U;
const int N = 55;
int Ans[N][N][N];

int lcs(int i, int j, int k) {
    if (i == S.size() || j == T.size() || k == U.size()) {
        return 0;
    }
    int &ans = Ans[i][j][k];
    if (ans != -1) {
        return ans;
    }
    ans = 0;
    if (S[i] == T[j] && T[j] == U[k]) {
        ans = 1 + lcs(i + 1, j + 1, k + 1);
    }
    else {
        ans = max({lcs(i + 1, j, k), lcs(i, j + 1, k), lcs(i, j, k + 1)});
    }
    return ans;
}

void Try() {
    cin >> S >> T >> U;
    memset(Ans, -1, sizeof Ans);
    cout << lcs(0, 0, 0) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        Try();
    }
    return 0;
} 