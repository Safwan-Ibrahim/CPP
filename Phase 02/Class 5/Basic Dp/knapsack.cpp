// Created on: 2025-03-22 02:19
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int N = 105;
int n, w, W[N], V[N];
int Dp[N][100005];

int go(int i, int weight) {
    if (i == n + 1) {
        return 0;
    }
    if (Dp[i][weight] != -1) {
        return Dp[i][weight];
    }
    int ans = go(i + 1, weight);
    if (weight + W[i] <= w) {
        ans = max(ans, go(i + 1, weight + W[i]) + V[i]);
    }
    return Dp[i][weight] = ans;
} 

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> W[i] >> V[i];
    }
    
    memset(Dp, -1, sizeof Dp);
    cout << go(1, 0);

    return 0;
} 