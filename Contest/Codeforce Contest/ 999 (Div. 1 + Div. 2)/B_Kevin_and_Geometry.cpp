// Created on: 2025-01-20 21:06
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;

    map<int, int>mp;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        mp[x]++;
    }

    int bp = -1;
    for (auto [x, y] : mp) {
        if (y > 1) {
            bp = max(bp, x);
        }
    }

    if (bp == -1 ) {
        cout << -1 << endl; 
        return;
    }

    mp[bp] -= 2;
    if (mp[bp] == 0) {
        mp.erase(bp);
    }

    vector<int>v;
    for (auto [x, y] : mp) {
        for (int i = 1; i <= y; i++) {
            v.push_back(x);
        }
    }

    for (int i = 0; i + 1 < v.size(); i++) {
        if (2 * bp > v[i + 1] - v[i]) {
            cout << bp << " " << bp << " " << v[i] << " " << v[i + 1] << endl; 
            return; 
        }
    }

    cout << -1 << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 