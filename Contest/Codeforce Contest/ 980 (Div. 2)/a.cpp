// Created on: 2024-10-20 15:08
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int a,b; cin >> a >> b;
    if (a >= b) {
        cout << a << endl;
    }
    else {
        int d = b - a;
        if (d <= a) {
            cout << a - d << endl;
        } 
        else {
            cout << 0 << endl;
        }
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