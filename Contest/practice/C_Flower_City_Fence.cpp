// Created on: 2025-08-06 21:25
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

    int mx = 0;
    vector<int>Dif(n + 5, 0);
    for (int i = 1; i <= n; i++) {
        mx = max(A[i], mx);
        if (A[i] <= n) {
            Dif[1]++;
            Dif[A[i] + 1]--;
        }
    }

    if (mx > n) {
        cout << "NO\n"; return;
    }

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += Dif[i];
        Dif[i] = sum;
    }

    for (int i = 1; i <= n; i++) {
        if (A[i] != Dif[i]) {
            cout << "NO\n"; return;
        }
    }

    cout << "YES\n";

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 