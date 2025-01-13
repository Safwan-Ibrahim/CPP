// Created on: 2024-11-08 15:51
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    char a,b; cin >> a >> b;
    int x = (int)a, y = (int)b;
    int limit = abs(x - y) + 1;

    for (int i = 1; i <= limit; i++) {
        if (x % i == y % i) {
            cout << i << " " << (94 + i - 1) / i  << endl;
        }
    }
    cout << endl;   
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 