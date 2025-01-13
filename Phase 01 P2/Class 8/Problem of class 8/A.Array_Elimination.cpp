// Created on: 2024-10-12 13:04
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    vector<int>cnt(31,0);

    for (int i = 1; i <= n; i++) {
        int e; cin >> e;
        for (int k = 0; k < 31; k++) {
            if ((e >> k) & 1) {
                cnt[k]++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        bool ok = 1;
        for (int k = 0; k < 31; k++) {
            if (cnt[k] % i != 0) {
                ok = 0; break;
            }
        }
        if (ok) {
            cout << i << " ";
        }
    }
    cout << endl;
       
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 