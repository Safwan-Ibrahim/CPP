// Created on: 2025-07-08 12:08
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 107, mod = 1e9 + 7;
int n, x, A[nn];

int way(int x) {
    // number of way to construct x from 1 to i = Way[i][x];
    vector<int>Prev(x + 3, 0), Cur(x + 3, 0);
    for (int i = 1; i <= n; i++) {
        Prev[0] = 1;
        Cur[0] = 1;
        for (int sum = 1; sum <= x; sum++) {
            Cur[sum] = Prev[sum];
            if (sum - A[i] >= 0) {
                Cur[sum] += Cur[sum - A[i]];
            }
            Cur[sum] %= mod;
        }
        Prev = Cur;
    }   
    return Cur[x];
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    sort(A + 1, A + n + 1);
    cout << way(x) << endl;

    return 0;
} 