// Created on: 2024-11-09 14:46
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(int x)
{   
    ll n,p; cin >> n >> p;
    cout << "Case " << x << ": ";
    
    ll half = n / 2;
    if (n == 1) {
        if (p == 1) {
            cout << "Evenius\n";
        }
        else {
            cout << "Oddius\n";
        }
    }
    else if ((n & 1) && !(half & 1)) {
        if (p == 1) {
            cout << "Oddius\n";
        }
        else {
            cout << "Evenius\n";
        }
    }
    else {
        cout << "Oddius\n";
    }
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
} 