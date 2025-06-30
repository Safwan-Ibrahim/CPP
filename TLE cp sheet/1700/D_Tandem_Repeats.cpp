// Created on: 2025-06-29 01:06
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

string S;
int n;

void Try() {
    cin >> S; n = S.size();
    vector<vector<int>> Ok(n + 1, vector<int>(n + 1, 0));
    
    for (int len = n - (n & 1); len > 0; len -= 2) {
        for (int i = 0; i + len / 2 < n; i++) {
            Ok[len][i] = (S[i] == S[i + len / 2] || S[i] == '?' || S[i + len / 2] == '?');
            if (i != 0) {
                Ok[len][i] += Ok[len][i - 1];
            }
        }
    }
    
    for (int len = n - (n & 1); len > 0; len -= 2) {
        for (int j = 0; j + len - 1 < n; j++) {
            if (Ok[len][j + len / 2 - 1] - (j == 0 ? 0 : Ok[len][j - 1]) == len / 2) {
                cout << len << endl; return;
            }
        }
    }

    cout << 0 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 