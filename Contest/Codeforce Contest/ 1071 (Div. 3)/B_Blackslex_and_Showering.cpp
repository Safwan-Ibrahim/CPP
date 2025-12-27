// Created on: 2025-12-23 20:56
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn];

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    int sum = 0, mx = 0;
    for (int i = 1; i + 1 <= n; i++) {
        sum += abs(A[i] - A[i + 1]);
    }

    for (int i = 1; i <= n; i++) {
        int prof = 0, cut = 0;
        if (i - 1 > 0) {
            prof += abs(A[i] - A[i - 1]);
        }
        if (i + 1 <= n) {
            prof += abs(A[i] - A[i + 1]);
        }
        if (i - 1 > 0 && i + 1 <= n) {
            cut += abs(A[i - 1] - A[i + 1]);
        }

        mx = max(mx, prof - cut);
    }

    cout << sum - mx << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 