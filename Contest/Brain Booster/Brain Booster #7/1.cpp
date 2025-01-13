// Created on: 2024-11-05 20:15
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int a,b; cin >> a >> b;
    if (b > a) {
        swap(a,b);
    }
    ll ans = 0;
    while(b > 0) {
        ans += a * b;
        a--,b--;
    }
    cout << ans << endl;
    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while(t--) solve();
    return 0;
} 