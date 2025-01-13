// Created on: 2024-10-08 21:01
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        int r,c; cin >> r >> c;
        vector<char>v(r,'*');
        cout << "Case " << i << ":" << endl;
        for (int j = 1; j <= c; j++) {
            for (auto x : v) {
                cout << x;
            }
            cout << endl;
        }
    }
    
    return 0;
} 