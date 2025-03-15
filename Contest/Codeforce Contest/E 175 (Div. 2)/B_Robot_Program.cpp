// Created on: 2025-02-27 20:51
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, x; ll k; cin >> n >> x >> k;
    char A[n + 5];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    int cnt = 0, pos = 0;
    bool yes = false;
    for (int i = 1; i <= n; i++) {
        if (A[i] == 'L') {
            pos--;
        }
        else {
            pos++;
        }
        cnt++;
        if (pos == 0) {
            yes = true;
            break;
        }
    }

    pos = x;
    ll ans = 0;
    int lost = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] == 'L') {
            pos--;
        }
        else {
            pos++;
        }
        lost++;
        if (pos == 0) {
            ans++;
            break;
        }
    }

    if (ans == 0) {
        cout << 0 << endl;
    }
    else {
        k -= lost;
        if (yes) {
            ans += k / cnt;
        }
        cout << ans << endl;
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 