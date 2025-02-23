// Created on: 2025-02-16 21:40
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 8;
ll Pref[N], Suf[N];
int A[N];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    Pref[0] = Suf[n + 1] = 0;
    for (int i = 1; i <= n; i++) {
        Pref[i] = Pref[i - 1];
        if (A[i] > 0) {
            Pref[i] += A[i];
        }
    }

    for (int i = n; i >= 1; i--) {
        Suf[i] = Suf[i + 1];
        if (A[i] < 0) {
            Suf[i] -= A[i];
        }
    }

    ll mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(Pref[i] + Suf[i], mx);
    }

    cout << mx << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 