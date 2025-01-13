// Created on: 2024-11-08 15:50
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void set_bit(ll& a, int k) {
    a = a | (1LL << k);
}

void off_bit(ll& a, int k) {
    a = a & ~(1LL << k);
}

bool is(ll a, int k) {
    return a >> k & 1;
}

void solve()
{
    ll a = 0, b, c, d; cin >> b >> c >> d;
    for (int i = 60; i >= 0; i--) {
        if (!is(b,i) && !is(c,i) && is(d,i)) {
            set_bit(a,i);
        }
        else if (is(b,i) && is(c,i) && !is(d,i)) {
            set_bit(a,i);
        }
    }
    if ((a | b) - (a & b) == d) {
        cout << a << endl;
    }
    else {
        cout << -1 << endl;
    }
    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 