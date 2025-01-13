// Created on: 2024-10-28 20:26
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int a,b,k; cin >> a >> b >> k;
    int n = min(a,b);
    cout << 0 << " " << 0 << " " << n << " " << n  << endl;
    cout << n << " " << 0 << " " << 0 << " " << n << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 