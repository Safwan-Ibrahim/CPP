// Created on: 2025-03-26 17:27
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 5e3 + 8, inf = 1e9;
string S, T;
int Ans[nn][nn];

int min_op(int i, int j) {
    if (i == S.size()) {
        return T.size() - j;
    }
    if (j == T.size()) {
        return S.size() - i;
    }
    if (Ans[i][j] != -1) {
        return Ans[i][j];
    }
    int ans = inf;
    if (S[i] == T[j]) {
        ans = min_op(i + 1, j + 1);
    }
    else {
        ans = min({ans, 1 + min_op(i + 1, j + 1), 1 + min_op(i + 1, j), 1 + min_op(i, j + 1)});
    }
    return Ans[i][j] = ans;
}

int min_op_it() {
    vector<vector<int>>Min_op(S.size() + 1, vector<int>(T.size() + 1, 0));
    for (int j = 0; j < T.size(); j++) {
        Min_op[S.size()][j] = T.size() - j;
    }

    for (int i = 0; i < S.size(); i++) {
        Min_op[i][T.size()] = S.size() - i;
    }

    for (int i = S.size() - 1; i >= 0; i--) {
        for (int j = T.size() - 1; j >= 0; j--) {
            if (S[i] == T[j]) {
                Min_op[i][j] = Min_op[i + 1][j + 1];
            }
            else {
                Min_op[i][j] = 1 + min({Min_op[i + 1][j], Min_op[i + 1][j + 1], Min_op[i][j + 1]});
            }
        }
    }

    return Min_op[0][0];
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> S >> T;
    // memset(Ans, -1, sizeof Ans);
    // cout << min_op(0, 0) << endl;
    cout << min_op_it() << endl;
    
    return 0;
} 