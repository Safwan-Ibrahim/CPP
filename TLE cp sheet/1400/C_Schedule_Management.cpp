// Created on: 2025-05-03 20:54
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, m, A[nn];

bool ok(int x) {
    ll extra = 0, need = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] <= x) {
            extra += (x - A[i]) / 2;
        }
        else {
            need += A[i] - x;
        }
    }
    return need <= extra;
}

void Try() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        A[x]++;
    }

    int lo = 1, hi = 2 * m, ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if (ok(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    cout << ans << endl;
    memset(A, 0, (n + 2) * 4);
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 