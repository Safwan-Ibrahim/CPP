// Created on: 2024-10-08 22:15
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    int n; cin >> n;
    map<char,int>mp;
    for (int i = 1; i <= n; i++) {
        char c; int a; cin >> c >> a;
        mp[c] = a-1;
    }
    
    map<char,int>cnt;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (mp.find(s[i]) != mp.end()) {
            cnt[s[i]]++;
        }
        else {
            ans++;
        }
    }

    for (auto [x,y] : cnt) {
        ans += ((y+mp[x]-1)/mp[x]) * mp[x];
    }
    cout << ++ans << endl;
    
    return 0;
} 