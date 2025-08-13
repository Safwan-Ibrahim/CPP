// Created on: 2025-04-06 17:25
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 105, K = 10005, M = 100000007;
int n, k, A[nn];
// Ans[N][K];

// int way(int i, int sum) {
//     if (i == n + 1) {
//         return sum == k;
//     }
//     int &ans = Ans[i][sum];
//     if (ans != -1) {
//         return ans;
//     }
//     ans = way(i + 1, sum);
//     if (sum + A[i] <= k) {
//         ans += way(i, sum + A[i]);
//     }
//     ans %= M;
//     return ans;
// }

int way_it() {
    vector<vector<int>>Way(n + 2, vector<int>(k + 2, 0));
    Way[n + 1][k] = 1;
    for (int i = n; i >= 1; i--) {
        for (int sum = k; sum >= 0; sum--) {
            Way[i][sum] = Way[i + 1][sum];
            if (sum + A[i] <= k) {
                Way[i][sum] += Way[i][sum + A[i]];
            }   
            Way[i][sum] %= M;
        }
    }
    return Way[1][0];
}

void Try() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int sum = 0; sum <= k; sum++) {
    //         Ans[i][sum] = -1;
    //     }
    // }
    // cout << way(1, 0) << endl;
    cout << way_it() << endl;

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