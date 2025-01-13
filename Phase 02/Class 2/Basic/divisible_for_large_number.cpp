// Created on: 2025-01-04 03:36
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin >> s;
    int n; cin >> n;
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
        int d = s[i] - '0';
        num = (1LL * num * 10 + d) % n;
    }
    if (num == 0) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
    return 0;
} 