// Created on: 2025-02-14 14:14
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 9;
const int inf = 3e9;
int A[3][N];
int Pref_down[N], Suff_up[N];

void solve() {
    int n; cin >> n;
    for (int i = 1; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += A[2][i];
        Pref_down[i] = sum;
    }

    sum = 0;
    for (int i = n; i >= 1; i--) {
        sum += A[1][i];
        Suff_up[i] = sum;
    }

    Pref_down[0] = Suff_up[n + 1] = 0;
    
    int mn = inf;
    for (int i = 1; i <= n; i++) {
        int mx = max(Pref_down[i - 1], Suff_up[i + 1]);
        mn = min(mn, mx);
    }
    
    cout << mn << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 