// Created on: 2025-01-20 17:05
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n, k; cin >> n >> k;

    vector<int>v(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    v.push_back(INT_MAX);

    vector<int>s{v.begin(), v.end()};
    sort(s.begin() + 1, s.end());

    map<int, int>mp;
    for (int i = 1; i <= n; i++) {
        mp[s[i]] = s[i + 1];
    }

    int part = 0;
    for (int i = 1; i <= n; i++) {
        if (i == n) {
            part++;
        }
        else if (mp[v[i]] != v[i + 1]) {
            part++;
        }
    }

    //cerr << part << endl;
    cout << (part > k ? "No\n" : "Yes\n");

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 