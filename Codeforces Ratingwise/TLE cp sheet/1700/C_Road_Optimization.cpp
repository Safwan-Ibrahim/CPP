// Created on: 2025-07-07 16:40
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 507, inf = 1e9;
int n, k, lp, Time[nn], Point[nn];

int min_time_it() {
    vector<vector<int>>Last_mt(n + 3, vector<int>(n + 3, inf)), Cur_mt(n + 3, vector<int>(n + 3, inf));
    for (int taken = n; taken >= 1; taken--) {

        for (int prev = n; prev >= 1; prev--) {
            for (int i = n + 1; i >= prev; i--) {
                int ans;
                if (i == n + 1) {
                    if (taken < k) ans = inf;
                    else ans = Time[prev] * (lp - Point[prev]);
                }
                else {
                    ans = Time[prev] * (Point[i] - Point[prev]) + Last_mt[i + 1][i];
                    ans = min(ans, Cur_mt[i + 1][prev]);
                }
                Cur_mt[i][prev] = ans;
            }
        }
        
        Last_mt = Cur_mt;
    }
    return Cur_mt[2][1];
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> lp >> k; 
    k = n - k;
    for (int i = 1; i <= n; i++) {
        cin >> Point[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> Time[i];
    }
    cout << min_time_it() << endl;
    
    return 0;
} 