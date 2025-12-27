// Created on: 2025-04-30 23:32
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, q, l, need, A[nn], Pref[nn][31];

bool ok(int r) {
    int ans = 0;
    for (int k = 0; k < 31; k++) {
        int new_k = Pref[r][k] - Pref[l - 1][k];
        if (new_k == r - l + 1) {
            ans += (1 << k);
        } 
    }
    return ans >= need;
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    vector<int>B(31, 0);
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < 31; k++) {
            if (A[i] >> k & 1) {
                B[k]++;
            }
        }
        for (int k = 0; k < 31; k++) {
            Pref[i][k] = B[k];
        }
    }

    cin >> q;
    while(q--) {
        cin >> l >> need;
        int ans = -1;
        int lo = l, hi = n;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if (ok(mid)) {
                ans = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        cout << ans << " ";
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