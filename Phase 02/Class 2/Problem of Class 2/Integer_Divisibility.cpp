// Created on: 2025-01-07 04:39
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(int t) {
    int m, n; cin >> m >> n;

    int ans = 0, num = 0, ten = 1;
    while(1) {
        ans++;
        num = (num + ten) % m;
        ten = ten * 10 % m;
        if (1LL * n % m * num % m % m == 0) {
            cout << "Case " << t << ": ";
            cout << ans << endl; return;
        }
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int c = 1;
    int t = 1; cin >> t;
    while(t--) solve(c++);
    return 0;
} 