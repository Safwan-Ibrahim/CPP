// Created on: 2025-07-07 23:23
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 107, inf = 1e9;
int n, x, A[nn];

int min_coin() {
    // minimum coin needed to make x = Min[x];
    vector<int>Min_coin(x + 3, inf);
    Min_coin[0] = 0;
    for (int sum = 1; sum <= x; sum++) {
        for (int i = 1; i <= n && sum - A[i] >= 0; i++) {
            Min_coin[sum] = min(Min_coin[sum], 1 + Min_coin[sum - A[i]]);
        }
    }    
    return (Min_coin[x] >= inf ? -1 : Min_coin[x]);
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    sort(A + 1, A + n + 1);;
    cout << min_coin() << endl;
    
    return 0;
} 