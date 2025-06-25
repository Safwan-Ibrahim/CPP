// Created on: 2025-06-23 15:29
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void Try() {
    int n; cin >> n;
    int ans;
    cout << "mul 999999999" << endl;
    cin >> ans;
    cout << "digit" << endl;
    cin >> ans;
    if (n != 81) {
        cout << "add " << n - 81 << endl;
        cin >> ans;
    }
    cout << "!" << endl;
    cin >> ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 