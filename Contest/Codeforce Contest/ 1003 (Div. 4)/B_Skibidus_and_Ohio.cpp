// Created on: 2025-02-09 20:42
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    string S; cin >> S;

    bool ok = 0;
    for (int i = 0; i + 1 < S.size(); i++) {
        if (S[i] == S[i + 1]) {
            ok = true;
            break;
        }
    }

    if (!ok) {
        cout << S.size() << endl;
    }
    else {
        cout << 1 << endl;
    }
    
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 