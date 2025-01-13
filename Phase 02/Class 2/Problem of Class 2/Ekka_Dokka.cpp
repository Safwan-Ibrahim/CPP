// Created on: 2025-01-07 15:38
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve(int t) {
    ll n; cin >> n;

    ll two = 1;
    while(n % 2 == 0) {
        n /= 2;
        two *= 2;
    }

    cout << "Case " << t << ": ";
    if (two != 1) {
        cout << n << " " << two << endl;
    }
    else {
        cout << "Impossible\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1; cin >> t; int c = 1;
    while(t--) solve(c++);
    return 0;
} 