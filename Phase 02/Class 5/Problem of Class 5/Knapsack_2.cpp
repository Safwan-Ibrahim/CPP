// Created on: 2025-03-26 08:12
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 105, C = 1e5 + 8;
const ll inf = 1e15;
int n, w, V[nn], W[nn];
ll Ans[nn][C];

ll min_weight(int i, int total) {
    if (i == n + 1) {
        return (total == 0 ? 0 : inf);
    }
    if (Ans[i][total] != -1) { 
        return Ans[i][total];
    }
    ll ans = min_weight(i + 1, total);
    if (total - V[i] >= 0) {
        ans = min(ans, W[i] + min_weight(i + 1, total - V[i]));
    }
    return Ans[i][total] = ans;
}

int max_value_it() {
    vector<vector<ll>>Min_weight(n + 2, vector<ll>(C, inf));
    Min_weight[n + 1][0] = 0;
    for (int i = n; i >= 1; i--) {
        for (int total = 0; total <= 100000; total++) {
            Min_weight[i][total] = Min_weight[i + 1][total];
            int next = total - V[i];
            if (next >= 0) {
                Min_weight[i][total] = min(Min_weight[i][total], W[i] + Min_weight[i + 1][next]);
            }
        }
    }

    int mx = 0;
    for (int i = 1; i <= 100000; i++) {
        if (Min_weight[1][i] <= w) {
            mx = i;
        }
    }
    return mx;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> W[i] >> V[i];
    }

    // memset(Ans, -1, sizeof Ans);
    // int mx = 0;
    // for (int i = 1; i <= 100000; i++) {
    //     if (min_weight(1, i) <= w) {
    //         mx = i;
    //     }
    // }
    //cout << mx << endl;

    cout << max_value_it() << endl;
    return 0;
} 