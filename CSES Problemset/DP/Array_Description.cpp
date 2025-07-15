// Created on: 2025-07-08 17:47
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17, mod = 1e9 + 7;
int n, m, A[nn];

int total_way() {
    // if prev is k then number of way to construct array from i to n is Way[i][k];
    vector<int>Way_last(m + 3, 1), Way_cur(m + 3, 0);
    for (int i = n; i >= 2; i--) {
        for (int prev = m; prev >= 1; prev--) {
            Way_cur[prev] = 0;
            if (A[i] != 0 && abs(prev - A[i]) > 1) {
                continue;
            }
            if (A[i] != 0) {
                Way_cur[prev] = Way_last[A[i]]; continue;
            }
            for (int next = max(1, prev - 1); next <= min(m, prev + 1); next++) {
                Way_cur[prev] += Way_last[next];
                Way_cur[prev] %= mod;
            }
        }
        Way_last = Way_cur;
    }

    int ans = 0;
    if (A[1] != 0) ans = Way_last[A[1]];
    else {
        for (int i = 1; i <= m; i++) {
            ans += Way_last[i];
            ans %= mod;
        }
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    cout << total_way() << endl;
    
    return 0;
} 