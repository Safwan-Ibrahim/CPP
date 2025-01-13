// Created on: 2024-10-14 17:32
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    int x = 0;

    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        x |= a;
    }
    cout << x << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 