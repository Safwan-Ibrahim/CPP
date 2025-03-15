// Created on: 2025-02-24 23:19
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    string S; cin >> S;

    ll ans = 0, ok1 = 0, ok0 = 0;
    for (auto x : S) {
        if (x == '0') {
            ok0++;
            ok1 = 0;
            ans += ok0;
        }
        else if (x == '1') {
            ok1++;
            ok0 = 0;
            ans += ok1;
        }
        else {
            ok1++;
            ok0++;
            ans += max(ok0, ok1);
        }
        swap(ok1, ok0);
    }
    
    cout << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 