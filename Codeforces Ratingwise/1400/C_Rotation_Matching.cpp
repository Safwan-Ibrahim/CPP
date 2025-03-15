// Created on: 2025-03-07 03:39
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    map<int, int>Mp;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        Mp[x] = i;
    }

    map<int, int>RS;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        int need = Mp[x];
        if (need < i) {
            RS[n - i + need]++;
        }
        else {
            RS[need - i]++;
        }
    }

    int mx = 0;
    for (auto [x, y] : RS) {
        mx = max(mx, y);
    }
    cout << mx << endl;
    
    return 0;
} 