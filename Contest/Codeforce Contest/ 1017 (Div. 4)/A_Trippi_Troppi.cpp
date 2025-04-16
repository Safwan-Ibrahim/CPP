// Created on: 2025-04-13 21:35
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    string S; 
    getline(cin, S);
    stringstream ss(S);

    string ans = "";
    string t;
    while(ss >> t) {
        ans = ans + string() + t[0];
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    cin.ignore();
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 