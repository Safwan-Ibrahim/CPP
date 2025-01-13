// Created on: 2025-01-04 04:28
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll power(ll x, ll n, ll m) {
    ll ans = 1 % m, p2 = x;
    while(n) {
        if (n & 1) {
            ans = (__int128_t) ans * p2 % m; 
        }
        n >>= 1;
        p2 = (__int128_t) p2 * p2 % m;
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll a, b, m; cin >> a >> b >> m;
    ll mul = (__int128_t) a * b % m;
    ll p = power(a, b, m);

    b = power(b, m - 2, m);
    ll div = (__int128_t) a * b % m;

    cout << p << endl << mul << endl << div << endl;;

    return 0;
} 