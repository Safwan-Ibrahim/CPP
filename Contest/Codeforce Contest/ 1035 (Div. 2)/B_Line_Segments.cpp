// Created on: 2025-07-05 21:16
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn];

double dis(int x, int y, int x1, int y1) {
    return sqrt(1LL * (x1 - x) * (x1 - x) + 1LL * (y1 - y) * (y1 - y));
}

void Try() {
    cin >> n;
    int x, y, x1, y1; cin >> x >> y >> x1 >> y1;
    double d = dis(x, y, x1, y1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    sort(A + 1, A + n + 1);
    reverse(A + 1, A + n + 1);
    double mx, mn;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            mx = d + A[i];
            mn = abs(d - A[i]);
            if (mn == 0) {
                cout << "Yes\n"; return;
            }
        }
        else {
            mx += A[i];
            mn -= A[i];
            if (mx >= 0 && mn <= 0) {
                cout << "Yes\n"; return;
            }
        }
    }

    cout << "No\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 