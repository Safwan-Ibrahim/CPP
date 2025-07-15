// Created on: 2025-07-09 16:56
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

string Ans((int) 1e5 + 17, '9');

void Try() {
    int n; cin >> n;
    if (n == 1) {
        cout << -1 << endl; return;
    }
    Ans[n - 1] = '8';
    cout << Ans.substr(0, n) << endl;
    Ans[n - 1] = '9';
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 