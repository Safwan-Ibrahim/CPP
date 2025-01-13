// Created on: 2025-01-03 20:36
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 5e4 + 9, M = 1e9 + 7;
int sum[N], spf[N];

void do_spf() {
    for (int i = 1; i < N; i++) {
        spf[i] = i;
    }
    for (int i = 2; i < N; i++) {
        for (ll j = 1LL * i * i ; j < N; j += i) {
            spf[j] = min(spf[j], i);
        }
    }
}

void calculate(int i, map<int, int>&mp) {
    int ans = 1;
    for (auto [x, y] : mp) {
        ans = 1LL * ans * (y + 1) % M;
    }
    sum[i] = ans;
}

void primes_fact(int x, map<int, int>& mp) {
    while(x > 1) {
        mp[spf[x]]++;
        x /= spf[x];
    }
    return;
}

void solve() {
    int n; cin >> n; cout << sum[n] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    do_spf();
    
    map<int, int>mp;
    for (int i = 0; i < N; i++) {
        primes_fact(i, mp);  
        calculate(i, mp);
    }

    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 