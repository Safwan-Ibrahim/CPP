// Created on: 2025-04-24 20:44
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, x; cin >> n >> x;
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (cnt == x) {
            cnt++;
        }
        cout << cnt++ << " ";
    }
    cout << (x < n ? x : cnt) << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 