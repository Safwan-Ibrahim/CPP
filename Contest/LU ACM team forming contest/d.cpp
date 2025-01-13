// Created on: 2024-10-08 21:17
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
    map<char,char>mp;
    mp['1'] = '1'; mp['2'] = '2'; mp['3'] = 'E'; mp['5'] = '5';mp['6'] = '9'; mp['9'] = '6'; mp['8'] = '8'; mp['E'] = '3';
    mp['0'] = '0'; mp['A'] = '8';

    int ans = 0;
    for (int i = 0,j = s.size()-1; i <= j; i++,j--) {
        if (i == j) {
            if (mp.find(s[i]) != mp.end()) {
                continue;
            }
            else {
                ans++;
            }
        }
        if (mp.find(s[i]) != mp.end()) {
            if (mp[s[i]] == s[j]) {
                continue;
            }
            else {
                ans++;
            }
        }
        else if (mp.find(s[j]) != mp.end()){
            if (mp[s[j]] == s[i]) {
                continue;
            }
            else {
                ans++;
            }
        }
        else {
            ans += 2;
        }
    } 

    cout << ans << endl;

    
    
    return 0;
} 