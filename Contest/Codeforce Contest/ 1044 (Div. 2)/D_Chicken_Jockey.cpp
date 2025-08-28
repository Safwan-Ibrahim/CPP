// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn];

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    vector<ll> Min_cost(n + 2, 0);
    Min_cost[1] = A[1];
    for (int i = 2; i <= n; i++) {
        Min_cost[i] = min(Min_cost[i - 1] + A[i] - 1, Min_cost[i - 2] + A[i - 1] + max(0, A[i] - (i - 1)));
    }
    
    cout << Min_cost[n] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 