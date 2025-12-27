// Created on: 2025-11-14 20:59
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    string S; cin >> S;
    if (S.size() == 1) {
        cout << 1 << endl; return;
    }

    bool inf = false;
    for (int i = 0; i + 1 < S.size(); i++) {
        char c = S[i], d = S[i + 1];
        if (c == '*' && d == '*' || c == '>' && d == '*' || c == '*' && d == '<' || c == '>' && d == '<') inf = true;
    }

    if (inf) {
        cout << -1 << endl;
        return;
    }

    int n = S.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (S[i] == '<') {
            ans = max(ans, i + 1);
        }
        if (S[i] == '*') {
            ans = max(ans, i + 1);
            ans = max(ans, n - i);
        }
        if (S[i] == '>') {
            ans = max(ans, n - i);
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }

    return 0;
} 