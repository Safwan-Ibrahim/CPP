// Created on: 2025-05-11 22:11
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    int A[n + 3][n + 3];

    int num = n * n - 1;
    for (int st = 1, end = n; st <= end; st++, end--) {
        if (st == end) {
            A[st][end] = 0; break;
        }
        for (int col = st; col <= end; col++) {
            A[st][col] = num--;
        }
        for (int row = st + 1; row < end; row++) {
            A[row][st] = num--;
        }
        for (int col = st; col <= end; col++) {
            A[end][col] = num--;
        }
        for (int row = st + 1; row < end; row++) {
            A[row][end] = num--;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
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