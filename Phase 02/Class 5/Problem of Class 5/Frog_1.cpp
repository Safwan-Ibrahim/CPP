// Created on: 2025-03-24 04:34
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 8;
int A[N], Min_cost[N];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        Min_cost[i] = 2e9 + 8;
    }   

    Min_cost[n] = 0;
    for (int i = n; i >= 2; i--) {
        Min_cost[i - 1] = min(Min_cost[i - 1], abs(A[i] - A[i - 1]) + Min_cost[i]);
        if (i - 2 >= 1) {
            Min_cost[i - 2] = min(Min_cost[i - 2], abs(A[i] - A[i - 2]) + Min_cost[i]);
        }
    }

    cout << Min_cost[1] << endl;
    
    return 0;
} 