// Created on: 2025-03-25 17:21
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl '\n'

const int nn = 105;
int n, w, V[nn], W[nn];
ll Ans[nn][100005];

ll max_value(int i, int sum) {
    if (i == n + 1) {
        return 0;
    }
    if (Ans[i][sum] != -1) {
        return Ans[i][sum];
    }
    ll mx = max_value(i + 1, sum);
    if (sum + W[i] <= w) {
        mx = max(mx, V[i] + max_value(i + 1, sum + W[i]));
    }
    return Ans[i][sum] = mx;
}

ll max_value_it() {
    vector<vector<ll>>Max_value(n + 2, vector<ll>(w + 1, 0));
    for (int i = n; i >= 1; i--) {
        for (int sum = 0; sum <= w; sum++) {
            Max_value[i][sum] = Max_value[i + 1][sum];
            if (sum + W[i] <= w) {
                Max_value[i][sum] = max(Max_value[i][sum], V[i] + Max_value[i + 1][sum + W[i]]);
            }
        }
    }

    return Max_value[1][0];
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> W[i] >> V[i];
    }

    // memset(Ans, -1, sizeof Ans);
    // cout << max_value(1, 0) << endl;
    cout << max_value_it() << endl;
    
    return 0;
} 