// Created on: 2024-11-02 01:46
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        ans |= x;
    }

    cout << ans << endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 