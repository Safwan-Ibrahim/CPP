// Created on: 2024-11-25 19:24
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int x, y; cin >> x >> y; 
    if (x > y) {
        cout << x + y << endl;
    }
    else {
        cout << (y - y % x) + (y % x) / 2 << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 