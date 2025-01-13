// Created on: 2024-10-03 20:36
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    map<int,int>mp;

    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        mp[a]++;
    }


    for (auto [x , y] : mp) {
        if (y == 1) {
            cout << x << endl;
            return 0;
        }
    }

    
    
    return 0;
} 