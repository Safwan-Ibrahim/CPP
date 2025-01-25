// Created on: 2025-01-20 22:20
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int n, m, b[N];

#define ll long long
#define endl '\n'

bool check(map<int, int>&mp, int x) {
    
}

void solve() {
    cin >> n >> m;

    map<int, int>mp;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        mp[x]++;
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }


    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 