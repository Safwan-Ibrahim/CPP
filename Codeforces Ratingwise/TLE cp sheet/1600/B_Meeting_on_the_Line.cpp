// Created on: 2025-05-24 15:15
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, P[nn], T[nn];

double get_time(double x) {
    double mx = -1;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, abs(x - P[i]) + T[i]);
    }
    return mx;
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
    }    
    
    for (int i = 1; i <= n; i++) {
        cin >> T[i];
    }

    double lo = 0, hi = 1e8, ans, mn = 1e18;
    int it = 100;
    while(it--) {
        double mid = (lo + hi) / 2;
        double l = get_time(mid - 0.1), m = get_time(mid), r = get_time(mid + 0.1);
        if (m < mn) {
            ans = mid;
            mn = m;
        }
        if (l < r) hi = mid;
        else lo = mid;
    }

    cout << fixed << setprecision(7) << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 