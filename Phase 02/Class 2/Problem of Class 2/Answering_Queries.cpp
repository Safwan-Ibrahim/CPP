// Created on: 2025-01-13 09:58
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(int t) {
    int n, q; cin >> n >> q;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += 1LL * a[i] * (n - 2 * i - 1);
    }

    cout << "Case " << t << ":\n";
    while(q--) {
        int type; cin >> type;
        if (type) {
            cout << sum << endl;
        }
        else {
            int i, x; cin >> i >> x;
            int dif = x - a[i];
            sum += 1LL * dif * (n - 2 * i - 1);
            a[i] = x;
        }
    }
    
}
 
int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1; cin >> t; int c = 1;
    while(t--) solve(c++);
    return 0;
} 