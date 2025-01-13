// Created on: 2024-11-14 16:47
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n,a,b; cin >> n >> a >> b;
    string s; cin >> s;
    int it = 100000;
    int x = 0, y = 0;
    int i = 0;
    while(it--) {
        if (i == n) {
            i = 0;
        }
        if (s[i] == 'N') {
            y++;
        }
        else if (s[i] == 'E') {
            x++;
        }
        else if (s[i] == 'S') {
            y--;
        }
        else {
            x--;
        }
        if (x == a && y == b) {
            cout << "YES\n";return;
        }
        i++;
    }
    cout << "NO\n";
    
    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 