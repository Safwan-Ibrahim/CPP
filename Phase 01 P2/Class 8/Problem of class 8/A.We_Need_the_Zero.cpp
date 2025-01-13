// Created on: 2024-10-12 04:08
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    int a[n+1], ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans ^= a[i];
    }

    for (int k = 0; k < 9; k++) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += (a[i] >> k) & 1;
        }
        if (cnt % 2 && (n-cnt) % 2) {
            cout << -1 << endl; return;
        }
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