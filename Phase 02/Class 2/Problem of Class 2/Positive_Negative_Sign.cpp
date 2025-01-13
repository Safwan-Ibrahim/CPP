// Created on: 2025-01-07 20:49
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll sum (int n) {
    return 1LL * n * (n + 1) / 2;
}

void solve2(int t) {
    int n, m; cin >> n >> m;
    cout << "Case " << t << ": " << 1LL * n * m / 2 << endl;

}

void solve(int t) {
    int n, m; cin >> n >> m;

    ll f_sum = sum(m), s_sum = sum(2 * m) - f_sum; 

    ll m7 = m * 2;
    ll neg = n / m7 * f_sum + m * m7 * sum(n / m7 - 1), pos = n / m7 * s_sum + m * m7 * sum(n / m7 - 1);
    cout << "Case " << t << ": " << pos - neg << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1; cin >> t; int c = 1;
    while(t--) solve(c++);
    return 0;
} 