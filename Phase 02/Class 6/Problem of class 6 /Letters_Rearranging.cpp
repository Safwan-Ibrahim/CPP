// Created on: 2025-04-13 15:07
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    string S; cin >> S;
    sort(S.begin(), S.end());
    int n = S.size();
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        if (S[i] != S[j]) {
            cout << S << endl; return;
        }
    }

    cout << -1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 