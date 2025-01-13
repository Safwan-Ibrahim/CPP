// Created on: 2024-10-12 00:17
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int M = 1e9 + 7;

void solve()
{   
    int n,k; cin >> n >> k;
    int ans = 1;
    for (int i = 1; i <= k ;i++) {
        ans = 1LL * ans * n % M;
    }
    cout << ans << endl;
} 

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}