// Created on: 2025-07-03 17:57
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e6 + 17;
int n, A[nn], Cnt[nn];

ll get_count(int x) {
    ll ans = 0;
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s ^= A[i];
        Cnt[s]++;
    }
    s = 0;
    for (int i = 1; i <= n; i++) {
        ans += Cnt[x];
        x ^= A[i];
        s ^= A[i];
        Cnt[s]--;
    }
    return ans;
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    int hb = 0;
    for (int i = 1; i <= n; i++) {
        hb = max(hb, 31 - __builtin_clz(A[i]));
    }
    hb++;

    ll ans = 1LL * n * (n + 1) / 2;
    for (int i = 0; i * i <= (1 << hb); i++) {
        ans -= get_count(i * i);
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