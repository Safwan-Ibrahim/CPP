// Created on: 2024-10-14 20:30
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    string s,t; cin >> s >> t;
    int n = s.size() + t.size(); 
    int limit = min(s.size(),t.size());

    int mn = 0;
    for (int i = 0; i < limit; i++) {
        if(s[i] != t[i]) {
            break;
        }
        else {
            mn++;
        }
    }
    int left = n - (mn * 2);
    if (mn) {
        mn++;
    }
    cout << left + mn << endl;

    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 