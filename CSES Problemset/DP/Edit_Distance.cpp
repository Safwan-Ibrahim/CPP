// Created on: 2025-07-10 18:29
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    string A, B; cin >> A >> B;
    int an = A.size(), bn = B.size();
    vector<vector<int>>Ed(an + 3, vector<int>(bn + 3, 1e8));

    for (int i = an; i >= 0; i--) {
        for (int j = bn; j >= 0; j--) {
            if (i == an) Ed[i][j] = bn - j;
            else if (j == bn) Ed[i][j] = an - i;
            else {
                if (A[i] == B[j]) {
                    Ed[i][j] = Ed[i + 1][j + 1];
                }
                Ed[i][j] = min(Ed[i][j], 1 + Ed[i + 1][j]);
                Ed[i][j] = min(Ed[i][j], 1 + Ed[i][j + 1]);
                Ed[i][j] = min(Ed[i][j], 1 + Ed[i + 1][j + 1]);
            }
        }
    }

    cout << Ed[0][0] << endl;
    
    return 0;
} 