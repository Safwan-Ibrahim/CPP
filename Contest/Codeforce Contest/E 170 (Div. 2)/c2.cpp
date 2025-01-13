// Created on: 2024-10-14 21:53
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n,k; cin >> n >> k;
    map<int,int>mp;

    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        mp[a]++;
    }

    int ans = 0; auto it = mp.begin();
    int cnt = 0, dis = 0;
    for (auto i = mp.begin(); i != mp.end(); i++) {
        int f = i->first, s = i->second;
        dis++;
        cnt += s;
        if (dis < k) {
            ans = max(ans,cnt);
        }
        else if (dis == k) {
            ans = max(ans,cnt);
            cnt -= it->second;
            dis--;
            it++;
        }
        if (mp.find(f + 1) == mp.end()) {
            ans = max(ans,cnt);
            cnt = 0;
            dis = 0;
            it = mp.find(f);
            it++;
        }
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