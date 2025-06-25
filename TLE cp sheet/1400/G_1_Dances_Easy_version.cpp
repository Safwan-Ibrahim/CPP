// Created on: 2025-04-30 23:07
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8;
int n, m, Up[nn], Down[nn];

bool ok(int x) {
    for (int i = n - x + 1, j = 1; i <= n; i++, j++) {
        if (Down[i] <= Up[j]) {
            return 0;
        }
    }
    return 1;
}

void Try() {
    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        cin >> Up[i];
    }
    Up[1] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> Down[i];
    }

    sort(Up + 1, Up + n + 1);
    sort(Down + 1, Down + n + 1);

    int lo = 1, hi = n, ans = 0;
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

    cout << n - ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 