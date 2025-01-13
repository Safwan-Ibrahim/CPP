// Created on: 2025-01-01 16:48
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n, a, b, c; cin >> n >> a >> b >> c;
    vector<int>dv;
    for (int i = 1; 1LL * i * i <= n; i++) {
        if (n % i == 0) {
            dv.push_back(i);
            if (n / i != i) {
                dv.push_back(n / i);
            }
        }
    }
    sort(dv.begin(), dv.end());
    ll ans = 0;
    int lim = dv.size();
    for (int i = 0; i < lim && dv[i] <= a; i++) {
        for (int j = 0; j < lim && dv[j] <= b; j++) {
            ll down = (1LL * dv[i] * dv[j]);
            if (n % down == 0 && n / down <= c) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 