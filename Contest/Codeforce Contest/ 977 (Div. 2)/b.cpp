// Created on: 2024-10-06 12:01
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n,k; cin >> n >> k; 
    map<ll,int>mp;
    
    for (int i = 1; i <= n; i++) {
        ll a; cin >> a;
        mp[a]++;
    }

    int ans = 0, i = 0;
    for (auto [x,y] : mp) {
        if (x != i) {
            ans = i; break;
        }
        else if (y > 1) {
            mp[x+k] += y-1; 
        }
        i++;
        ans = x+1;
    }
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