// Created on: 2025-07-09 19:29
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        a += c == '1';
        b += c == '0';
    }
    cout << n - min(a, b) * 2 << endl;
    return 0;
}  