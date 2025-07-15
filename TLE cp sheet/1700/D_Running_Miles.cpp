// Created on: 2025-07-01 16:09
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 18;
int n, A[nn];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    vector<int>Pref(n + 2, 0), Suf(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        Pref[i] = A[i] + i;
    }
    for (int i = n; i >= 1; i--) {
        Suf[i] = A[i] - i;
    }

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, Pref[i]);
        Pref[i] = mx;
    }
    mx = Suf[n];
    for (int i = n; i >= 1; i--) {
        mx = max(mx, Suf[i]);
        Suf[i] = mx;
    }

    mx = 0;
    for (int i = 2; i < n; i++) {
        mx = max(A[i] + Pref[i - 1] + Suf[i + 1], mx);
    }
    cout << mx << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 