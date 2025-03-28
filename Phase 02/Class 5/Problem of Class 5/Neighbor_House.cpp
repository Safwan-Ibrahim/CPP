// Created on: 2025-03-27 00:55
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 22, inf = 2e9;
int n, A[3][N], Ans[3][N];

int min_cost(int last, int id) {
    if (id == n + 1) {
        return 0;
    }
    if (Ans[last][id] != -1) {
        return Ans[last][id];
    }
    int ans = inf;
    for (int i = 0; i < 3; i++) {
        if (i == last) {
            continue;
        }
        ans = min(ans, A[i][id] + min_cost(i, id + 1));
    }
    return Ans[last][id] = ans;
}

int min_cost_it() {
    vector<vector<int>>Min_cost(3, vector<int> (n + 2, 0));

    for (int i = n; i >= 1; i--) {
        Min_cost[0][i] = min(A[1][i] + Min_cost[1][i + 1], A[2][i] + Min_cost[2][i + 1]);
        Min_cost[1][i] = min(A[0][i] + Min_cost[0][i + 1], A[2][i] + Min_cost[2][i + 1]);
        Min_cost[2][i] = min(A[0][i] + Min_cost[0][i + 1], A[1][i] + Min_cost[1][i + 1]);
    }

    return min({Min_cost[0][1], Min_cost[1][1], Min_cost[2][1]});
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[0][i] >> A[1][i] >> A[2][i];
    }
    
    memset(Ans, -1, sizeof Ans);
    cout << min({min_cost(0, 1), min_cost(1, 1), min_cost(2, 1)}) << endl;
    // cout << min_cost_it() << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        Try();
    }
    return 0;
} 