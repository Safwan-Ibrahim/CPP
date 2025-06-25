// Created on: 2025-04-24 06:54
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

map<int, int>Mp;

pair<bool, ll> isrt(ll x) {
    ll ans = sqrt(x);
    while(ans * ans >= x) {
        ans--;
    }
    while(ans * ans < x) {
        ans++;
    }
    pair<int, int> p;
    p.first = ans * ans == x;
    p.second = ans;
    return p;
}

void prec() {
    int a = 3;
    int total = 0;
    while((1LL * a * a - 1) / 2 <= 1e9) {
        ll b = (1LL * a * a - 1) / 2; {
            ll need = 1LL * a * a + 1LL * b * b;
            auto p = isrt(need);
            if (p.second > 1e9) {
                break;
            }
            if (p.first) {
                total++;
                Mp[p.second] = total;
            }
        }
        a++;
    }
}

void Try() {
    int n; cin >> n;
    auto it = Mp.upper_bound(n);
    if (it != Mp.begin()) {
        it--;
        cout << it->second << endl;
    }
    else {
        cout << 0 << endl;
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    prec();
    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 