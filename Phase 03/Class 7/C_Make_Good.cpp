// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int n, A[nn];

void bit_on(ll& x, int k) {
    x = (1 << k) | x;
}

void Try() {
    cin >> n;

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        mx = max(mx, A[i]);
    }

    int msb = 31 - __builtin_clz(mx) + 1;
    vector<ll> Ans(3, 0);
    Ans[0] = (1 << msb) - 1;

    for (int k = 0; k < msb; k++) {
        int cnt = 1;
        for (int i = 1; i <= n; i++) {
            cnt += (A[i] >> k) & 1;
        }
        if (cnt % 2) {
            bit_on(Ans[1], k);
        }
    }

    ll sum = Ans[0] + Ans[1];
    ll x = Ans[1] ^ Ans[0];
    for (int i = 1; i <= n; i++) {
        sum += A[i];
        x ^= A[i];
    }

    Ans[2] = sum;
    assert((x ^ Ans[2]) * 2 == sum + Ans[2]);

    cout << Ans.size() << endl;
    cout << Ans[0] << " " << Ans[1] << " " << Ans[2] << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 