// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    string S = to_string(n);
    for (int i = n; i < 1e9; i += n) {
        string A = to_string(i);
        ll m = stoll(S + A);
        if (m % (i + n) == 0) {
            cout << i << " ";
            break;
        }
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 