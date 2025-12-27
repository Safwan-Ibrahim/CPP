// Created on: 2025-05-20 15:48
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e7;
vector<int> Cnt(10, 0);

void prec() {
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j + i <= 9; j++) {
            for (int k = 0; i + j + k <= 9; k++) {
                Cnt[i + j + k]++;
            }
        }
    }
}

void Try() {
    int n; cin >> n;
    ll ans = 1;
    while(n > 0) {
        ans = 1LL * ans * Cnt[n % 10]; 
        n /= 10;
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1; cin >> t; prec();
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 