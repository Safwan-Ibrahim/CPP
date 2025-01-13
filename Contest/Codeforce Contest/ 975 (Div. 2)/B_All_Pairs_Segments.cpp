// Created on: 2024-10-06 10:56
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n,q; cin >> n >> q;
    map<double,int>mp;

    for (int i = 1; i <= n; i++) {
        double a; cin >> a;
        mp[a] += n-i;
        mp[a+.9] -= i-1;
    }

    ll sum = 0;
    for (auto [x,y] : mp) {
        sum += y;
        mp[x] = sum;
    }

    for (auto [x,y] : mp) {
        if (round(x) > x) {
            mp.erase(x);
        }
    }

    map<int,int>seg;

    auto limit = --mp.end();
    for (auto it = mp.begin(); it != limit; it++) {
        int f = (*it).first, s = (*it).second;
        it++;
        int f2 = (*it).first;
        seg[s] += f2-f;
        it--;
    }
    
    for (auto [x,y] : mp) {
        cout << x << " " << y << endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 