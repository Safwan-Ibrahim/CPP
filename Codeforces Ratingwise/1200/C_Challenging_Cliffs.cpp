// Created on: 2025-02-10 18:21
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<int>A(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    if (n == 2) {
        cout << A[0] << " " << A[1] << endl;
        return;
    }

    int dif = INT_MAX, pos = -1;
    for (int i = 0; i + 1 < n; i++) {
        if (A[i + 1] - A[i] < dif) {
            pos = i;
            dif = A[i + 1] - A[i];
        }
    }

    for (int i = pos + 1; i < n; i++) {
        cout << A[i] << " ";
    }

    for (int i = 0; i <= pos; i++) {
        cout << A[i] << " ";
    }

    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 