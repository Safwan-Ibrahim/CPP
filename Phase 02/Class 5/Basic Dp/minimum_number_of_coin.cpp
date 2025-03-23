// Created on: 2025-03-23 06:34
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 105, M = 1e6 + 8, inf = 2e9;
int n, x, A[N], Ans[N][M];

int min_num(int i, int sum) {
    if (sum > x) {
        return inf;
    }
    if (i == n + 1) {
        if (sum == x) {
            return 0;
        }
        return inf;
    }

    if (Ans[i][sum] != -1 ) {
        return Ans[i][sum];
    }
    int ans = min_num(i + 1, sum);
    ans = min(ans, 1 + min_num(i, sum + A[i]));
    return Ans[i][sum] = ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    memset(Ans, -1, sizeof Ans);
    cout << min_num(1, 0) << endl;

    
    return 0;
} 