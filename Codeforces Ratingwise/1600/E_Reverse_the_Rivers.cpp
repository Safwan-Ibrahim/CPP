// Created on: 2025-06-19 18:21
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'


void Try() {
    int n, k, q; cin >> n >> k >> q;
    vector<vector<int>> V(k, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> V[j][i];
        }
    }
    for (int i = 0; i < k; i++) {
        int orr = 0;
        for (int j = 0; j < n; j++) {
            orr |= V[i][j];
            V[i][j] = orr;
        }
    }
    
    while(q--) {
        int m; cin >> m;
        int l = 0, r = n + 1;
        while(m--) {
            int reg, limit; char sign;
            cin >> reg >> sign >> limit;
            bool big = sign == '>';
            reg--;
            if (big) {
                l = max((int) (upper_bound(V[reg].begin(), V[reg].end(), limit) - V[reg].begin()), l);
            }
            else {
                r = min((int) (lower_bound(V[reg].begin(), V[reg].end(), limit) - V[reg].begin()) + 1, r);
            }
        }
        cout << (l + 1 < r ? l + 1 : -1) << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; //cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 