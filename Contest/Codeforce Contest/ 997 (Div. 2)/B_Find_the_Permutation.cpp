// Created on: 2025-01-17 21:17
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1005;
char A[N][N];
int n, Ans[N];

void Solve(vector<int>B, int l, int r) {
    if (l > r) {
        return;
    }
    int cnt = 0;
    vector<int>L, R;
    int mn = B.front();
    for (int i = 1; i < B.size(); i++) {
        if (A[mn][B[i]] == '1') {
            cnt++;
            R.push_back(B[i]);
        }
        else {
            L.push_back(B[i]);
        }
    }

    Ans[r - cnt] = mn;
    Solve(R, r - cnt + 1, r);
    Solve(L, l, r - cnt - 1);
} 

void Try() {
    cin >> n;
    
    vector<int>B;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
        B.push_back(i);
    }

    memset(Ans, 0, n * 4);
    Solve(B, 1, n);
    
    for (int i = 1; i <= n; i++) {
        cout << Ans[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 