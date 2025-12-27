// Created on: 2025-12-11 20:46
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    string S; cin >> S;
    
    int s = S.size();
    S += S;

    int last = 0, mx = 0;
    for (int i = S.size() - 1; i >= 0; i--) {
        if (S[i] == '1') last = i;
        if (S[i] == '0' && i < s) mx = max(mx, last - i);
    }
    
    cout << mx << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 