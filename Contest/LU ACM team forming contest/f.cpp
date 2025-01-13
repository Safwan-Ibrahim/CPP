// Created on: 2024-10-12 21:25
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
    vector<int>ans{n};

    while(n > 0) {
        ans.push_back(n/3);
        if (n > 2) {
            n++;
            n = n/3 + n%3;
        }
    }

    cout << (accumulate(ans.begin(),ans.end(),0));
    
    return 0;
} 
