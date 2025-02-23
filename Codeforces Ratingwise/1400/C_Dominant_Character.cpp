// Created on: 2025-02-23 02:02
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    string S; cin >> S;
    int mn = 10;
    for (int i = 0; i + 1 < n; i++) {
        if (S[i] == 'a' && S[i + 1] == 'a') {
            mn = min(mn, 2);
        }
        if (i + 2 < n) {
            string t = S.substr(i, 3);
            if (t == "aba" || t == "aca") {
                mn = min(mn, 3);
            }
        }  
        if (i + 3 < n) {
            string t = S.substr(i, 4);
            if (t == "abca" || t == "acba") {
                mn = min(mn, 4);
            }
        }
        if (i + 6 < n) {
            string t = S.substr(i, 7);
            if (t == "abbacca" || t == "accabba") {
                mn = min(mn, 7);
            }
        }
    }
    cout << (mn == 10 ? -1 : mn) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 