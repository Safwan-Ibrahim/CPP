// Created on: 2024-10-24 20:34
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    bool sak = true;
    int i = 0;
    int a = 1;
    while(i >= -n && i <= n) {
        if(sak) {
            i -= 2 * a - 1;
            sak = false;
        }
        else {
            i += 2 * a - 1;
            sak = true;
        }
        a++;
    }
    if (sak) {
        cout << "Kosuke\n";
    }
    else {
        cout << "Sakurako\n";
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