// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    
    string S, T; cin >> S;
    T = S;
    sort(T.begin(), T.end());

    int ans = 0;
    for (int i = 0; i < S.size(); i++) {
        ans += S[i] != T[i];
    }
    
    cout << ans / 2 << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 