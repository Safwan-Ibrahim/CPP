// Created on: 2025-07-13 20:42
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    string S; cin >> S;    
    for (int i = 1; i < S.size(); i++) {
        char c = S[i];
        c = (c == 'a' ? 'z' : char(c - 1));
        if (c != S[i - 1]) {
            cout << "NO\n"; return;
        }
    }
    cout << "YES\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t; 
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 