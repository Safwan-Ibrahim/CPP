// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int e = min(a, b), f = max(a, b);
    d -= b, c -= a;
    int g = min(d, c), h = max(d, c);
    if ((f + 1) / 2 - 1 <= e && (h + 1) / 2 - 1 <= g) cout << "YES\n";
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