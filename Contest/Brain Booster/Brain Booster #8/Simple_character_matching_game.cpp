// Created on: 2025-02-17 21:06
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int num_of_row, num_of_col; cin >> num_of_row >> num_of_col;
    char A[num_of_row + 5][num_of_col + 5];
    for (int row = 1; row <= num_of_row; row++) {
        for (int col = 1; col <= num_of_col; col++) {
            cin >> A[row][col];
        }
    }

    int pref[num_of_row + 5][num_of_col + 5];
    int suf[num_of_row + 5][num_of_col + 5];

    for (int i = 0; i <= num_of_row + 1; i++) {
        for (int j = 0; j <= num_of_col + 1; j++) {
            pref[i][j] = 0;
            suf[i][j] = 0;
        }
    }
    
    
    for (int col = 1; col <= num_of_col; col++) {
        map<char, int>mp;
        for (int row = 1; row <= num_of_row; row++) {
            mp[A[row][col]]++;
            int mx = -1;
            for (auto [x , y] : mp) {
                mx = max(mx, y);
            }
            pref[row][col] = mx;
        }
    }

    for (int col = 1; col <= num_of_col; col++) {
        map<char, int>mp;
        for (int row = num_of_row; row >= 1; row--) {
            mp[A[row][col]]++;
            int mx = -1;
            for (auto [x, y] : mp) {
                mx = max(mx, y);
            }
            suf[row][col] = mx;
        }
    }

    ll mx = -1;
    for (int row = 0; row <= num_of_row; row++) {
        ll sum1 = 0, sum2 = 0;
        for (int col = 1; col <= num_of_col; col++) {
            sum1 += pref[row][col];
            sum2 += suf[row + 1][col];
        }
        mx = max(mx, sum1 + sum2);
    }

    cout << mx << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 