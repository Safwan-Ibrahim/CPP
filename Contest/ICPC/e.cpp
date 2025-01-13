// Created on: 2024-11-09 14:47
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
const int M = 998244353;

ll power(int x, int n) {
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * x % M;
    }
    return ans;
}


void solve()
{
    int n,m,k; cin >> n >> m >> k;
    ll ans = power(k - 1, m - 1);
    ans = ans * k % M;
    ans = ans * n;
    cout << ans << endl;
    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 