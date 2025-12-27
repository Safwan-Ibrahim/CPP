// Created on: 2025-12-11 02:33
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int prefix_xor(int x) {
    if (x % 4 == 0) return x;
    if (x % 4 == 1) return 1;
    if (x % 4 == 2) return x + 1;
    return 0;
}

int range_xor(int l, int r) {
    return prefix_xor(r) ^ prefix_xor(max(0LL, l - 1));
}

void set_bit(int& x, int k) {
    x |= (1LL << k);
}

void Try() {
    int l, r, i, k; cin >> l >> r >> i >> k;

    int p = (1LL << i);
    int full = range_xor(l, r);

    int nl = l;
    if (nl % p <= k) nl += k - (nl % p);
    else {
        nl += p;
        nl -= (nl % p) - k;
    }

    int cnt = 0;
    if (l <= nl && nl <= r) cnt++;

    if (nl + 1 <= r) {
        cnt += (r - nl) / p;
    }

    int ans = 0;
    for (int j = 0; j < i && cnt % 2; j++) {
        if ((nl >> j) & 1) set_bit(ans, j);
    }

    nl >>= i;
    if (cnt) {
        int x = range_xor(nl, nl + cnt - 1);

        for (int j = 0; j + i < 63; j++) {
            if ((x >> j) & 1) set_bit(ans, i + j);
        }
    }

    cout << (ans ^ full) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 