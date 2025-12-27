// Created on: 2025-05-05 10:50
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e3 + 8, mod = 1e9 + 7;
int n, k, Ans[nn][nn]; 

int way(int taken, int value) {
    if (taken == k) {
        return 1;
    }
    int &ans = Ans[taken][value];
    if (ans != -1) {
        return ans;
    }
    ans = 0;
    for (int i = value; i <= n; i += value) {
        ans += way(taken + 1, i);
        ans %= mod; 
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    
    memset(Ans, -1, sizeof Ans);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += way(1, i);
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
} 