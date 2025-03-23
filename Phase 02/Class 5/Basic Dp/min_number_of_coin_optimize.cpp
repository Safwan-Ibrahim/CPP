// Created on: 2025-03-23 06:34
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 105, M = 1e6 + 8, inf = 2e9;
int n, x, A[N], Min_coin[N][M], Min_coin2[2][M];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    Min_coin[0][0] = 0;
    for (int sum = 1; sum <= x; sum++) {
        Min_coin[0][sum] = inf;
    }

    for (int i = 1; i <= n; i++) {
        for (int sum = 0; sum <= x; sum++) {
            int ans = Min_coin[i - 1][sum];
            if (sum - A[i] >= 0) {
                ans = min(ans, Min_coin[i][sum - A[i]] + 1);
                ans = min(ans, Min_coin[i - 1][sum - A[i]] + 1);
            }
            Min_coin[i][sum] = ans;
        }
    }
    
    Min_coin2[0][0] = 0;
    for (int sum = 1; sum <= x; sum++) {
        Min_coin2[0][sum] = inf;
    }

    for (int i = 1; i <= n; i++) {
        for (int sum = 0; sum <= x; sum++) {
            int ans = Min_coin2[0][sum];
            if (sum - A[i] >= 0) {
                ans = min(ans, Min_coin2[1][sum - A[i]] + 1);
                ans = min(ans, Min_coin2[0][sum - A[i]] + 1);
            }
            Min_coin2[1][sum] = ans;
        }
        
        for (int sum = 0; sum <= x; sum++) {
            Min_coin2[0][sum] = Min_coin2[1][sum];
        }
    }

    //cout << (Min_coin[n][x] >= inf ? -1 : Min_coin[n][x]) << endl;
    cout << (Min_coin2[1][x] >= inf ? -1 : Min_coin2[1][x]) << endl;

    
    return 0;
} 