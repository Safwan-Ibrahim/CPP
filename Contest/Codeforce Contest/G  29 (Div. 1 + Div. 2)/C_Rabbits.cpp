// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'


void Try() {
    int n; cin >> n;
    string S; cin >> S;

    vector<bool> L(n, 0), R(n, 0);
    int last = -1;
    for (int i = 0; i < n; i++) {
        if (S[i] != '0') continue;
        if (i == 0) L[i] = R[i] = true;
        if (i - 1 >= 0 && S[i - 1] == '0' && (R[i - 1] || L[i - 1])) L[i] = R[i] = true;
        if (i - 2 >= 0 && S[i - 2] == '0' && R[i - 2]) L[i] = true;
        if (i - 2 >= 0 && S[i - 2] == '0' && L[i - 2]) R[i] = true;
        if (last == -1 || L[last]) R[i] = true;
        last = i;
    }

    if (last == -1 || (last == n - 1 && (L[last] || R[last])) || L[last]) cout << "YES\n";
    else cout << "NO\n";

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 