// Created on: 2025-03-24 01:27
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e6 + 8, M = 1e9 + 7;
int Ans[nn];

int ways(int x) {
    if (x < 0) {
        return 0;
    }
    if (x == 0) {
        return 1;
    }
    if (Ans[x] != -1) {
        return Ans[x];
    }
    int ans = 0;
    for (int i = 1; i <= 6; i++) {
        ans += ways(x - i);
        ans %= M;
    }
    return Ans[x] = ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    memset(Ans, -1, sizeof Ans);
    cout << ways(n) << endl;
    
    return 0;
} 