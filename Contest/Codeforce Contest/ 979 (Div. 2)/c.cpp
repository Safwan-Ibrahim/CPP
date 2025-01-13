// Created on: 2024-10-19 20:55
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    if (s[0] == '1') {
        cout << "YES\n"; return;
    }
    for (int i = 0; i < s.size(); i++) {
        if (i == s.size() - 1) {
            if (s[i] == '1') {
                cout << "YES\n"; return;
            }
        }
        else {
            if (s[i] == '1' && s[i + 1] == '1') {
                cout << "YES\n"; return;
            }
        }
    }

    cout << "NO\n"; 
}

int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 