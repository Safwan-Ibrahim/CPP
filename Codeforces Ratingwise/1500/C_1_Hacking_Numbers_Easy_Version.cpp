// Created on: 2025-06-03 06:06
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void Try() {
    int n; cin >> n; char c;
    cout << "digit" << endl; cin >> c;
    cout << "digit" << endl; cin >> c;
    cout << "add -8" << endl; cin >> c;
    cout << "add -4" << endl; cin >> c;
    cout << "add -2" << endl; cin >> c;
    cout << "div 2" << endl; cin >> c;
    cout << "mul " << n << endl; cin >> c;
    cout << "!" << endl; cin >> n;
    cout.flush();
}

int32_t main() {
    ios_base::sync_with_stdio(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 