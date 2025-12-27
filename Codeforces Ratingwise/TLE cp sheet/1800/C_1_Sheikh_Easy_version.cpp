// Created on: 2025-11-12 12:11
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int n, q, A[nn], Px[nn];
ll Ps[nn];

bool ok(int l, int r, ll need) {
    return Ps[r] - Ps[l] - (Px[r] ^ Px[l]) == need;
}

void Try() {
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    for (int i = 1; i <= n; i++) {
        Ps[i] = Ps[i - 1] + A[i];
        Px[i] = Px[i - 1] ^ A[i];
    }

    while (q--) {
        int l, r; cin >> l >> r; l--;

        ll need = Ps[r] - Ps[l] - (Px[r] ^ Px[l]);
        pair<int, int> ans = {l, r};
        for (int i = l; i < r; i++) {

            int lo = i + 1, hi = r;
            while (lo <= hi) {
                int mid = lo + hi >> 1;

                if (ok(i, mid, need)) {
                    if (ans.second - ans.first > mid - i) {
                        ans = {i, mid};
                    }
                    hi = mid - 1;
                }
                else lo = mid + 1;
            }
        }

        cout << ans.first + 1 << " " << ans.second << endl;
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