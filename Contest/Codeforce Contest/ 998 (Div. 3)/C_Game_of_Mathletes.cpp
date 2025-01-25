// Created on: 2025-01-19 21:15
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n, k; cin >> n >> k;

    map<int, int>mp;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        mp[x]++;
    }

    int ans = 0;
    while(mp.size() > 0) {
        auto it = mp.begin();
        int need = k - it->first;
        if (need * 2 != k) {
            ans += min(it->second, mp[need]);
            mp.erase(it);
            mp.erase(need);
        }
        else {
            ans += mp[need] / 2;
            mp.erase(need);
        }
    }
    
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 