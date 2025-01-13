// Created on: 2024-10-01 04:45
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n,q; cin >> n >> q;
    ll a[n+5];
    memset(a,0,sizeof(a)); 

    vector<pair<int,int>>v;

    while(q--) {
        int l,r; cin >> l >> r;
        a[l]++;
        a[r+1]--;
        v.push_back(make_pair(r+1,r-l+1));
    }

    for (int i = 1; i <= n; i++) {
        a[i] += a[i-1];
    }

    for (auto [x,y] : v) {
        a[x] -= y;
    }

    for (int i = 1; i <= n; i++) {
        a[i] += a[i-1];
        cout << a[i] << " ";
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