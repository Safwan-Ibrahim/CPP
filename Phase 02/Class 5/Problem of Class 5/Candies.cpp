// Created on: 2025-04-02 03:47
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 105, M = 1e9 + 7;
int n, k, A[nn];

// int way(int id, int need_to_take) {
//     if (id == n + 1) {
//         if (need_to_take == 0) {
//             return 1;
//         }
//         return 0;
//     }
//     int ans = 0;
//     for (int i = 0; i <= A[id]; i++) {
//         ans += way(id + 1, need_to_take - i);
//     }
//     return ans;
// }

int way_it() {
    vector<vector<int>>Way(n + 5, vector<int>(k + 1, 0));
    vector<int>Pref(k + 1, 1);
    Way[n + 1][0] = 1;
    for (int id = n; id >= 1; id--) {
        for (int need_to_take = 0; need_to_take <= k; need_to_take++) {
            int l = max(0, need_to_take - A[id]), r = need_to_take;
            // for (int take = 0; take <= min(need_to_take, A[id]); take++) {
            //     Way[id][need_to_take] += Way[id + 1][need_to_take - take];
            // }
            Way[id][need_to_take] = (Pref[r] - (l ? Pref[l - 1] : 0) + M) % M;
        }
        int sum = 0;
        for (int need_to_take = 0; need_to_take <= k; need_to_take++) {
            sum += Way[id][need_to_take];
            sum %= M;
            Pref[need_to_take] = sum;
        }
    }
    return Way[1][k];
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    // cout << way(1, k) << endl;
    cout << way_it() << endl;
    
    return 0;
} 