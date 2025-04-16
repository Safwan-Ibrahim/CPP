// Created on: 2025-04-11 14:37
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    
    int n, k; cin >> n >> k;
    vector<int> a(n); for(auto &e : a) cin >> e;

    map<int, int> mp;
    for(auto e : a) mp[e]++;

    while (k--)
    {
        int cmd; cin >> cmd;
        if(cmd == 2)
        {
            if(mp.count(0)) mp.erase(0);
            cout << mp.size() << endl;
        }
        else 
        {
            int pos, data; cin >> pos >> data;

            int toDel = a[pos-1];   

            if(mp.count(toDel)) mp[toDel]--;
            if(mp[toDel] == 0) mp.erase(toDel);
            mp[data]++;

            a[pos - 1] = data;
            

        }
    }
    //for(auto e : a) cout << e << " "; cout << endl ;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 