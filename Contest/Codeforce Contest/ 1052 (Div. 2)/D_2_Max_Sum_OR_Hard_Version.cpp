// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int l, r; cin >> l >> r;

    map<int, int> Ans;
    map<int, bool> Vs;
    for (int i = l; i <= r; i++) {
        Ans[i] = i;
        Vs[i] = false;
    }

    for (int all = (1 << 30) - 1; all > 0; all >>= 1) {
        for (int i = r; i >= l; i--) {
            if (Vs[i]) continue;
            int need = all ^ i;
            if (need > r || need < l) continue;
            if (Vs[need]) continue;
            Vs[i] = Vs[need] = true;
            swap(Ans[i], Ans[need]);
        }
    }

    ll ans = 0;
    for (int i = l; i <= r; i++) {
        ans += Ans[i] | i;
    }

    cout << ans << endl;
    for (auto x : Ans) {
        cout << x.second << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 