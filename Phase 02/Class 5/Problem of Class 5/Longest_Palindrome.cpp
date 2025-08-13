// Created on: 2025-03-28 21:10
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1005;
string S, T; 
int Ans[nn][nn];

int lps(int i, int j) {
    if (j == i) {
        return 1;
    }
    if (i > j) {
        return 0;
    }
    int &ans = Ans[i][j];
    if (ans != -1) {
        return ans;
    }
    ans = 0;
    if (S[i] == S[j]) {
        ans = 2 + lps(i + 1, j - 1);
    }
    else {
        ans = max(lps(i + 1, j), lps(i, j - 1));
    }
    return ans;
}

int lps_it() {
    int n = S.size();   
    vector<vector<int>>Lps(n + 5, vector<int>(n + 5, 0));
    for (int i = n - 1; i >= 0; i--) {
        Lps[i][i] = 1;
        for (int j = i + 1; j <= n; j++) {
            if (S[i] == S[j]) {
                Lps[i][j] = 2;
                if (i + 1 <= j - 1) {
                    Lps[i][j] += Lps[i + 1][j - 1];
                }
            }
            else {
                Lps[i][j] = max(Lps[i + 1][j], Lps[i][j - 1]);
            }
        }
    }
    return Lps[0][n - 1];
}

void Try() {
    getline(cin, S);
    // for (int i = 0; i < S.size(); i++) {
    //     for (int j = 0; j < S.size(); j++) {
    //         Ans[i][j] = -1;
    //     }
    // }
    //cout << lps(0, (int) S.size() - 1) << endl;
    cout << lps_it() << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    cin.ignore();
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 