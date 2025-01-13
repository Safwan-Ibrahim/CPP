// Created on: 2024-10-08 20:57
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'


void solve()
{
    double r; cin >> r;
    double pi = 3.141599998802696, ans = pi*r*r;
    cout << fixed << setprecision(3) << ans << endl;
    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 