// Created on: 2025-11-29 20:40
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n; n *= 2;

    map<int, int> Mp;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        Mp[x]++;
    }
    
    int ans = 0;
    int e = 0, o = 0, p = 0;
    for (auto [x, y] : Mp) {
        if (y % 2 == 1) {
            o++; ans++;
        }
        else {
            e++, ans += 2;
            if (y % 4 == 0) p++;
        }
    } 

    if (p % 2 && !o) ans -= 2;
    
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 