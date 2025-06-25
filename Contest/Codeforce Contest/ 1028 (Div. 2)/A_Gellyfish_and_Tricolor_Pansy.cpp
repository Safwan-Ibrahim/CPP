// Created on: 2025-05-31 20:39
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int g, f; cin >> g >> f;
    int x; cin >> x; g = min(g, x); cin >> x; f = min(f, x);
    if (g >= f) cout << "Gellyfish\n";
    else cout << "Flower\n"; 
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 