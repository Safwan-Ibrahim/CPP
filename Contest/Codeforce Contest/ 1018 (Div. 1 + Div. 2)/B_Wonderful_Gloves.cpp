// Created on: 2025-04-19 21:00
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, A[2][nn], k;

void Try() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[0][i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> A[1][i];
    }

    int V[n + 5];
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (A[0][i] > A[1][i]) {
            ans += A[0][i];
            V[i] = A[1][i];
        }
        else {
            ans += A[1][i];
            V[i] = A[0][i];
        }
    }

    k--;
    sort(V + 1, V + n + 1);
    for (int i = n; i >= n - k + 1; i--) {
        ans += V[i];
    }

    cout << ans + 1 << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 