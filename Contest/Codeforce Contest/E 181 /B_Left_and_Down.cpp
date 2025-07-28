// Created on: 2025-07-22 20:44
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

pair<ll, ll>get(ll a, ll b) {
    ll g = gcd(a, b);
    return {a / g, b / g};
}
 
void Try() {
    ll a, b, k; cin >> a >> b >> k;
    pair<ll, ll>p = get(a, b);
    if (p.first <= k && p.second <= k) {
        cout << 1 << endl; 
    }
    else cout << 2 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 