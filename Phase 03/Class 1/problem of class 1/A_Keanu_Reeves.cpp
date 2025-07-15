// Created on: 2025-07-09 19:38
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    string S; cin >> S;
    int a = 0, b = 0;
    for (auto c : S) {
        a += c == '0';
        b += c == '1';
    }

    if (a != b) {
        cout << 1 << endl;
        cout << S << endl; return 0;
    }

    cout << 2 << endl;
    cout << S.substr(0, n - 1) << " " << S.back() << endl;
    
    return 0;
} 