// Created on: 2025-11-19 19:15
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, L[nn], R[nn];

void Try() {
    cin >> n;

    vector<pair<int, int>> A;
    for (int i = 1; i <= n; i++) {
        cin >> L[i] >> R[i];
        A.push_back({L[i], R[i]});
    }

    sort(L + 1, L + n + 1);
    sort(R + 1, R + n + 1);

    int mx = 1;
    for (auto [l, r] : A) {
        int sr = lower_bound(R + 1, R + n + 1, l) - (R + 1);
        int gl = (L + n + 1) - upper_bound(L + 1, L + n + 1, r);
        mx = max(n - gl - sr, mx);
    }

    cout << n - mx << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 