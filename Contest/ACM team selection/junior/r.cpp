// Created on: 2025-08-01 10:06
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int lis(vector<int>&V) {
    int n = V.size();
    vector<int>Dp(n + 1, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (V[j] < V[i]) {
                Dp[i] = max(Dp[i], Dp[j] + 1);
            }
        }
    }
    return *max_element(Dp.begin(), Dp.end());
}

int lds(vector<int>&V) {
    int n = V.size();
    vector<int>Dp(n + 1, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (V[j] > V[i]) {
                Dp[i] = max(Dp[i], Dp[j] + 1);
            }
        }
    }  
    return *max_element(Dp.begin(), Dp.end());
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    vector<int>V = {1, 2, 3, 4, 5, 6};
    do {
        if (lis(V) == lds(V)) {
            for (auto x : V) {
                cout << x << " ";
            }
            cout << endl;
            break;
        }
    }
    while(next_permutation(V.begin(), V.end()));
    
    return 0;
} 