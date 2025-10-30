// Created on: 2025-10-28 22:16
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;

    int A[n + 1], C[n + 1];
    A[0] = C[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> C[i];
        sum += C[i];
    }

    vector<ll> Max_cost(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] <= A[i]) {
                Max_cost[i] = max(Max_cost[i], C[i] + Max_cost[j]);
            }
        }
    }

    ll mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, Max_cost[i]);
    }

    cout << sum - mx << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 