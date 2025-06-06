// Created on: 2024-11-15 18:26
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        if (a[i] == i) {
            continue;
        }
        if (a[i] == i + 1 && a[i + 1] == i) {
            swap(a[i], a[i + 1]);
        }
        else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    
    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 