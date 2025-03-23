// Created on: 2025-03-20 16:15
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int Dp[100005];

int fibo(int i) {
    if (i <= 1) {
        return i;
    }
    if (Dp[i] != -1) {
        return Dp[i];
    }
    return Dp[i] = fibo(i - 1) + fibo(i - 2);
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);


    int n; cin >> n;
    memset(Dp, -1, (n + 1) * 8);
    cout << fibo(n) << " ";
    
    return 0;
} 