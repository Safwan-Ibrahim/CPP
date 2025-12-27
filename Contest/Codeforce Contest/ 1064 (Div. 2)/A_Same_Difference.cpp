// Created on: 2025-11-16 20:35
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    string S; cin >> S;
    char c = S.back();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += S[i] == S.back();
    }
    
    cout << n - cnt << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 