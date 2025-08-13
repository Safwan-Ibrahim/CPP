// Created on: 2025-03-25 00:33
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8, inf = 2e9 + 8;
int n, k, A[nn], Ans[nn];

int min_cost(int x) {
    if (x == n) {
        return 0;
    }
    if (Ans[x] != -1) {
        return Ans[x];
    }
    int ans = inf;
    for (int i = x + 1, j = 1; i <= n && j <= k; i++, j++) {
        ans = min(ans, min_cost(i) + abs(A[x] - A[i]));
    }
    return Ans[x] = ans;
}

int min_cost_iterative() {

    vector<int>Min_cost(n + 1, inf);
    Min_cost[n] = 0;
    for (int i = n; i >= 2; i--) {
        for (int j = i - 1, lim = 1; j >= 1 && lim <= k; j--, lim++) {
            Min_cost[j] = min(Min_cost[j], abs(A[i] - A[j]) + Min_cost[i]);
        }
    }
    return Min_cost[1];
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    // memset(Ans, -1, sizeof Ans);
    // cout << min_cost(1) << endl;

    cout << min_cost_iterative() << endl;
    
    return 0;
} 