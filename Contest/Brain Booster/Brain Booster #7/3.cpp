// Created on: 2024-11-05 20:16
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n,k; cin >> n >> k;
    int a[n + 1], b[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b + 1, b + n + 1);
    int l = 0,r = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) {
            l = i;
            break;
        }
    }
    for (int i = n; i >= 1; i--) {
        if (a[i] != b[i]) {
            r = i;
            break;
        }
    }

    if(l) {
        if (r - l + 1 <= k) {
            cout << "YES\n";
            cout << l << " " << r << endl;
            return;
        } 
    }
    cout << "NO\n";
    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while(t--) solve();
    return 0;
} 