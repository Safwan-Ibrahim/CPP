// Created on: 2024-10-24 19:53
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    int a[n + 1]; a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        a[i] ^= a[i - 1];
    }

    vector<int>cnt(30,0);
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < 30; k++) {
            cnt[k] += (a[i] >> k) & 1;
        }
    }

    ll sum = 0;
    for (int k = 0; k < 30; k++) {
        ll con = 1LL * cnt[k] * (n + 1 - cnt[k]);
        sum += (con << k);
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