// Created on: 2025-03-28 09:11
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 3e3 + 8;
string S, T;
int Ans[nn][nn];

int lcs(int i, int j) {
    if (i == S.size() || j == T.size()) {
        return 0;
    }
    int &ans = Ans[i][j];
    if (ans != -1) {
        return ans;
    }
    if (S[i] == T[j]) {
        ans = 1 + lcs(i + 1, j + 1);
    }
    else {
        ans = max(lcs(i + 1, j), lcs(i, j + 1));
    }
    return ans;
}

void print(int i, int j) {
    if (i == S.size() || j == T.size()) {
        return;
    }
    if (S[i] == T[j]) {
        cout << S[i];
        print(i + 1, j + 1);
        return;
    }
    int l = lcs(i + 1, j);
    int r = lcs(i, j + 1);
    if (l > r) {
        print(i + 1, j);
    }
    else {
        print(i, j + 1);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> S >> T;

    memset(Ans, -1, sizeof Ans);
    print(0, 0);
    cout << endl;

    return 0;
} 