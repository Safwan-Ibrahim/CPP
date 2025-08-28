// Created on: 2025-08-20 05:08
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, q, A[nn]; ll Ps[nn];

ll get_sum(ll r) {
    int k = r / n;
    ll ans = k * Ps[n];
    int len = r % n;
    k++;
    if (len > 0) {
        if (k + len - 1 <= n) {
            ans += Ps[k + len - 1] - Ps[k - 1];
        }
        else {
            ans += Ps[n] - Ps[k - 1] + Ps[k + len - 1 - n];
        }
    }
    return ans;
}

void Try() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++) {
        Ps[i] = Ps[i - 1] + A[i];
    }

    while(q--) {
        ll l, r; cin >> l >> r;
        cout << get_sum(r) - get_sum(l - 1) << endl;
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