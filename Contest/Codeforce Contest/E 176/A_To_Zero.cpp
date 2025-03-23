// Created on: 2025-03-17 20:40
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, k; cin >> n >> k;
    int op = 0;
    if (n % 2 == 0) {
        k--;
        cout << (n + k - 1) / k << endl; return;
    }
    n -= k; op++;
    k--;
    op += (n + k - 1) / k;
    cout << op << endl;

    
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 