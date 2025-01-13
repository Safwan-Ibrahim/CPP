// Created on: 2024-10-12 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int r,c; cin >> r >> c;
    int good_c = c % 3;

    if (!good_c) {
        good_c = 3;
    }
    if (r % 4 == good_c % 4) {
        cout << "Vanya\n";
    }
    else {
        cout << "Tuzik\n";
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