// Created on: 2025-02-25 20:48
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    int z = 0, o = 0;
    for (int i = 1; i <= n; i++) {
        char x; cin >> x;
        if (x == '-') {
            o++;
        }
        else {
            z++;
        }
    }
    
    int a = o / 2, b = z, c = o / 2;
    if (o & 1) {
        c++;
    }

    cout << 1LL * a * b * c << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 