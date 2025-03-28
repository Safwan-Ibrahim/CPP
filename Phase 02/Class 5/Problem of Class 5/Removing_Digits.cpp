// Created on: 2025-03-25 01:15
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int inf = 2e9, N = 1e6 + 8;
int Ans[N];

int mx(int x) {
    int mx = 1;
    while(x > 0) {
        mx = max(mx, x % 10);
        x /= 10;
    }
    return mx;
}

int min_dp(int x) {
    if (x == 0) {
        return 0;
    }
    if (Ans[x] != -1) {
        return Ans[x];
    } 
    int n = x;
    int mn = inf;
    while(n > 0) {
        if (n % 10 != 0) {
            mn = min(mn, 1 + min_dp(x - n % 10));
        }
        n /= 10;
    }
    return Ans[x] = mn;
}

int iter(int n) {
    int st = 0;
    while(n > 0) {
        n -= mx(n);
        st++;
    }
    return st;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    memset(Ans, -1, sizeof Ans);
    cout << min_dp(n) << endl;
    
    return 0;
} 