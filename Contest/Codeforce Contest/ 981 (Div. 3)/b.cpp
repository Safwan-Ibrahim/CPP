// Created on: 2024-10-24 20:59
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        int mn = 1e8;
        int k = i - 1;
        for (int j = 1; j <= i; j++) {
            mn = min(mn,a[j][n - k]);
            k--;
        } 
        if (mn < 0) {
            sum += abs(mn);
        }
    }

    for (int i = 1; i <= n - 1; i++) {
        int mn = 1e8;
        int k = i + 1;
        for (int j = 1; j <= n - i; j++) {
            mn = min(mn,a[k][j]);
            k++;
        }
        if (mn < 0) {
            sum += abs(mn);
        }
    }

    cout << sum << endl;
    
    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 