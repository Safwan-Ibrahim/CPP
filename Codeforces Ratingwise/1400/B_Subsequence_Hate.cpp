// Created on: 2025-03-07 19:27
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int inf = INT_MAX;

void Try() {
    string S; cin >> S;
    int n = S.size();

    int sfx0 = 0, sfx1 = 0;
    for (int i = 0; i < n; i++) {
        sfx0 += S[i] == '0';
        sfx1 += S[i] == '1';
    }

    int mn = inf;
    int pfx0 = 0, pfx1 = 0;
    for (int i = 0; i < n; i++) {
        mn = min({mn, pfx0 + sfx1, pfx1 + sfx0});
        sfx0 -= S[i] == '0';
        sfx1 -= S[i] == '1';
        pfx0 += S[i] == '0';
        pfx1 += S[i] == '1';
    }
    cout << mn << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 