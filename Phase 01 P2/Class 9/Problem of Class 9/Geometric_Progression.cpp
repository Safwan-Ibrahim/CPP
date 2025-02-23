// Created on: 2025-02-20 03:39
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int power(int x, ll n, int m) {
    int ans = 1 % m;
    while(n > 0) {
        if (n & 1) {
            ans = 1LL * ans * x % m;
        }
        n >>= 1;
        x = 1LL * x * x % m;
    }
    return ans;
}

int sum(int a, ll x, int m) {
    if (x == 0) {
        return 1 % m;
    }
    int ans = sum(a, x / 2, m);
    if (x & 1) {
        return (ans + 1LL * ans * power(a, x / 2 + 1, m) % m) % m;
    }
    else {
        return (ans + 1LL * (ans - 1) * power(a, x / 2, m) % m) % m;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int a, m; ll x; cin >> a >> x >> m;
    cout << sum(a, x - 1, m) << endl;
    
    return 0;
} 