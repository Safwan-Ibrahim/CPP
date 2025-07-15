// Created on: 2025-07-09 16:39
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, x; cin >> n >> x;
    vector<int>Cnt(110, 0);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        Cnt[x]++;
    }

    int ans = 0;
    for (int i = 0; i < x; i++) {
        ans += Cnt[i] == 0;
    }
    ans += Cnt[x];
    cout << ans << endl;
    return 0;
} 