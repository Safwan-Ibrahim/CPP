// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 3e5 + 17;
int n, m, A[nn];

void Try() {
    cin >> m >> n;

    vector<int> V[2];
    for (int i = 1; i <= m; i++) {
        cin >> A[i];
        V[A[i] & 1].push_back(A[i]);
    }
    
    ll ans = 1LL * (n + 1) * (n + 2) / 2;
    for (int i = 1; i <= m; i++) {
        ans -= n - A[i] + 1;
        ans -= (A[i] + 2) / 2;
        int id = A[i] & 1;
        auto it = upper_bound(V[id].begin(), V[id].end(), A[i]);
        ans += it - V[id].begin();
    }

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