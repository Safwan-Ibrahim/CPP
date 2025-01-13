// Created on: 2024-11-05 20:16
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        cnt += s[i] == '?';
    }
    
    for (int t = 1; t <= min(k,cnt); t++) {
        
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