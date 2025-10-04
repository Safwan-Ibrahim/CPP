// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;

    map<int, int> Mp;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        Mp[x]++;
    }

    vector<int> O;
    ll a = 0, b = 0;
    for (auto [x, y] : Mp) {
        a += 1LL * x / 2 * y;
        b += 1LL * x / 2 * y;
        if (x & 1) O.push_back(y);
    }

    sort(O.rbegin(), O.rend());

    for (int i = 0; i < O.size(); i++) {
        if (i & 1) b += O[i];
        else a += O[i];
    }

    cout << a << " " << b << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 