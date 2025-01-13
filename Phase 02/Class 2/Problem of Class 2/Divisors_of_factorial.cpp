// Created on: 2025-01-09 07:32
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int M =  1e9 + 7, N = 5e4 + 7;
int dvs[N], spf[N];
map<int,int>mp;

void get_div(int n) {
    int key = n;

    while(n > 1) {
        mp[spf[n]]++;
        n /= spf[n];
    }

    int d = 1;
    for (auto [x, y] : mp) {
        d = 1LL * d * (y + 1) % M;
    }
    dvs[key] = d;
}

void prec() {
    for (int i = 1; i < N; i++) {
        spf[i] = i;
    }
    for (int i = 2; i < N; i++) {
        for (int j = i; j < N; j += i) {
            spf[j] = min(i, spf[j]);
        }
    }

    for (int i = 0; i < N; i++) {
        get_div(i);
    }
}

void solve() {
    int n; cin >> n; 
    cout << dvs[n] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    prec();
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 