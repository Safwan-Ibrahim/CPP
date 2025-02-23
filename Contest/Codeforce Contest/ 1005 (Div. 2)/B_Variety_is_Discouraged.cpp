// Created on: 2025-02-16 20:53
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 9;
int A[N];

void solve() {
    int n; cin >> n;
    map<int, int>Mp;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        Mp[A[i]]++;
    }

    set<int>St;
    for (auto [x, y] : Mp) {
        if (y >= 2) {
            St.insert(x);
        }
    }
    
    int mx = 0, ans_l = -1, ans_r = -1, prev_i = 1;
    for (int i = 1; i <= n; i++) {
        if (St.find(A[i]) != St.end()) { // in the set. means it occurs at least twice in array
            if (i - prev_i > mx) {
                mx = i - prev_i;
                ans_l = prev_i;
                ans_r = i - 1;
            }
            prev_i = i + 1;
        }
        else if (i == n) {
            if (i - prev_i + 1 > mx) {
                mx = i - prev_i + 1;
                ans_l = prev_i;
                ans_r = i;
            }
            prev_i = i + 1;
        }
    }

    if (mx == 0) {
        cout << mx << endl;
    }
    else {
        cout << ans_l << " " << ans_r << endl;
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