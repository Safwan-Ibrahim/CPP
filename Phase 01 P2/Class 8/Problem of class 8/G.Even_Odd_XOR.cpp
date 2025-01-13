// Created on: 2024-11-01 20:25
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    int x = 0;
    for (int i = 1; i <= n - 3; i++) {
        cout << i << " ";
        x ^= i;
    }

    int a = 1 << 28, b = 1 << 30, c = a ^ b ^ x;
    cout << a << " " << b << " " << c << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 