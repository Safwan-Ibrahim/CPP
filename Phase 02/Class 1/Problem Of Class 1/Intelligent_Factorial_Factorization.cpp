// Created on: 2025-01-02 18:23
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void primes_fact(int x, map<int, int>&mp) {
    for (int i = 2; i * i <= x; i++) {
        while(x % i == 0) {
            mp[i]++;
            x /= i;
        }
    }
    if (x > 1) {
        mp[x]++;
    }
    return;
}

void solve(int t) {
    int n; cin >> n;
    map<int, int>cp;
    for (int i = 2; i <= n; i++) {
        primes_fact(i, cp);
    }
    cout << "Case " << t << ": " << n << " = ";
    int cnt = 0;
    for (auto [x, y] : cp) {
        cout << x << " " << "(" << y << ")";
        cnt++;
        if (cnt < cp.size()) {
            cout << " * ";
        }
        else {
            cout << endl;
        }
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    int c = 1;
    while(t--) solve(c++);
    return 0;
} 