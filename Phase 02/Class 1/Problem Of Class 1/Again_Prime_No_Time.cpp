// Created on: 2025-01-03 14:50
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 9;
int spf[N];

void sp() {
    for (int i = 2; i < N; i++) {
        spf[i] = i;
    }

    for (int i = 2; i < N; i++) {
        for (int j = i; j < N; j += i) {
            spf[j] = min(spf[j], i);
        }
    }
}

void prime_fact(int n, map<int, int>&mp) {
    while(n > 1) {
        mp[spf[n]]++;
        n /= spf[n];
    }
    return;
}

void solve(int t) {
    cout << "Case " << t << ":\n";

    int n, m; cin >> m >> n;
    map<int, int>pf_n, pf_m;
    for (int i = 2; i <= n; i++) {
        prime_fact(i, pf_n);
    }
    prime_fact(m, pf_m);

    int ans = INT_MAX;
    for (auto [x, y] : pf_m) {
        ans = min(ans, pf_n[x] / y);
    }
    if (ans == 0) {
        cout << "Impossible to divide\n"; 
    }
    else {
        cout << ans << endl;    
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    sp();
    int c = 1;
    int t = 1; cin >> t;
    while(t--) solve(c++);
    return 0;
} 