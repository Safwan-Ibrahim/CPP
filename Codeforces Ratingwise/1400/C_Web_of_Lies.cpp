// Created on: 2025-03-16 03:21
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n, m; cin >> n >> m;
    vector<int>A(n + 1, 0);
    while(m--) {
        int u, v; cin >> u >> v;
        int mn = min(u, v);
        A[mn]++;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += A[i] != 0;
    }

    int q; cin >> q;
    while(q--) {
        int ty; cin >> ty;
        if (ty == 3) {
            cout << n - cnt << endl; continue;
        }
        int u, v; cin >> u >> v;
        int mn = min(u, v);
        if (ty == 1) {
            A[mn]++;
            if (A[mn] == 1) {
                cnt++;
            }
        }
        else {
            A[mn]--;
            if (A[mn] == 0) {
                cnt--;
            }
        }
    }
    
    return 0;
} 