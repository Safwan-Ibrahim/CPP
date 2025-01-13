// Created on: 2024-11-05 20:16
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{   
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        int a = 0;
        bool en = false;
        while(i < n && s[i] == '0') {
            a++;
            i++;
            en = 1;
        }
        if(en) {
            i--;
        }
        ans = max(ans,a);
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