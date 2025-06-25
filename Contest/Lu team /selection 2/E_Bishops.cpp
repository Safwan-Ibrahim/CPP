// Created on: 2025-04-18 15:20
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
    if ((r1 + c1) % 2 != (r2 + c2) % 2) {
        cout << "impossible\n"; return;
    }
    int dif1 = abs(r2 - r1), dif2 = abs(c2 - c1);
    if (dif1 == dif2)  {
        cout << 1 << endl;
    }
    else {
        cout << 2 << endl;
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        Try();
    }
    return 0;
} 