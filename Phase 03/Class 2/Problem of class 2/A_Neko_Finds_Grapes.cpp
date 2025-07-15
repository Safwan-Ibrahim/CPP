// Created on: 2025-07-10 20:35
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, m; cin >> n >> m;
    int odd1 = 0, odd2 = 0, even1 = 0, even2 = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x & 1) odd1++;
        else even1++;
    }
    
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        if (x & 1) odd2++;
        else even2++;
    }
    
    cout << min(odd1, even2) + min(even1, odd2) << endl;
    return 0;
} 