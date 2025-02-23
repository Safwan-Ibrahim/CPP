// Created on: 2024-11-24 20:38
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int power(int x, ll n, int m) {
    int ans = 1;
    while(n > 0) {
        if (n & 1) {
            ans = 1LL * ans * x % m;
        }
        x = x * x % m;
        n >>= 1;
    }
    return ans;
}

void solve()
{
    int a; ll b; cin >> a >> b;
    cout << power(a, b, 10) << endl;
    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 