// Created on: 2025-03-20 18:52
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e3 + 8, M = 1e9 + 7;
int Dp[N];

int count(int x) {
    if (x == 0) {
        return 1;
    }
    if (Dp[x] != -1) {
        return Dp[x];
    }
    int ans = 0;
    for (int i = 1; i <= x; i++) {
        ans += count(i - 1);
        ans %= M;
    }
    return Dp[x] = ans;
}

int sum_except_last_2;

int better_ways_to_count(int x) {
    if (x == 0) {
        sum_except_last_2 = 0;
        return 1;
    }
    int ans_of_last_one = better_ways_to_count(x - 1) ;
    int ans = (ans_of_last_one + sum_except_last_2) % M;
    sum_except_last_2 = (sum_except_last_2 + ans_of_last_one) % M;
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        Dp[i] = -1;
    }

    cout << count(n) << endl;
        
    return 0;
} 