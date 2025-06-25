// Created on: 2025-04-18 14:22
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n; 
    vector<int> a(n); for(auto &e : a) cin >> e;

    map<pair<int, int>, int> mp;
    mp[{1, 2}] = 3;
    mp[{2, 1}] = 3;
    mp[{1, 3}] = 4;
    mp[{3, 1}] = 4;
    mp[{2, 3}] = -1;
    mp[{3, 2}] = -1;

    int res = 0;
    for (int i = 0; i < n-1; i++)
    {
        int x = a[i], y = a[i + 1];

        if(mp[{x, y}] == -1)
        {
            cout << "Infinite" << endl; return 0;
        }

        res += mp[{x, y}]; // edge case
        if(i+2 < n && a[i] == 3 && a[i + 1] == 1 && a[i + 2] == 2) res--;
    }
    
    cout << "Finite" << endl;
    cout << res << endl;

    return 0;
} 