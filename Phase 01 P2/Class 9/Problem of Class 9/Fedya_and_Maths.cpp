// Created on: 2025-02-20 05:37
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    string S; cin >> S;
    int d = S.back() - '0';

    if (S.size() > 1) {
        d = (S[S.size() - 2] - '0') * 10 + d;
    }

    if (d % 4 == 0) {
        cout << 4 << endl;
    }
    else {
        cout << 0 << endl;
    }
    
    return 0;
} 