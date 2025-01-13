// Created on: 2024-11-15 18:26
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    map<int,int>mp;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    
    int mx = -1;
    for (auto [x,y] : mp) {
        mx = max(y,mx);
    }

    cout << n - mx << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 