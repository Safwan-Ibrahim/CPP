// Created on: 2024-10-08 23:57
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin >> n >> m;

    ll p = 0;
    map<ll,int>mp;
    for (int i = 1; i <= n; i++) {
        int a,b; cin >> a >> b;
        ll ans = a*b+p;
        p = ans;
        mp[ans] = i;
    }

    while(m--) {
        int a; cin >> a;
        cout << mp.lower_bound(a)->second << endl;
    }
    
    return 0;
} 