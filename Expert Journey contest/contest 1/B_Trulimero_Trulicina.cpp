// Created on: 2025-06-04 12:05
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int number_of_row, number_of_col, k; cin >> number_of_row >> number_of_col >> k;
    int sq = 0;
    for (int i = 1; i <= number_of_row; i++) {
        for (int j = 1; j <= number_of_col; j++) {
            cout << sq % k + 1 << " ";
            sq = (sq + 1) % k;
        }
        cout << endl;
        if (number_of_col % k == 0) sq ^= 1;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 