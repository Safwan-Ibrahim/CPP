// Created on: 2025-04-30 20:30
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e3 + 8;
ll n, k, A[nn];

void Try() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    if (k >= 3) {
        cout << 0 << endl; return;
    }
    ll mn = 2e18;
    vector<ll>V;
    for (int i = 1; i <= n; i++) {
        mn = min(mn, A[i]);
        for (int j = i + 1; j <= n; j++) {
            V.push_back(abs(A[i] - A[j]));
            mn = min(mn, V.back());
        }
    }

    if (k == 1) {
        cout << mn << endl; return;
    }

    sort(V.begin(), V.end());
    for (int i = 1; i <= n; i++) {
        auto it = upper_bound(V.begin(), V.end(), A[i]);
        if (it != V.end()) {
            mn = min(mn, abs(A[i] - *it));
        }
        if (it != V.begin()) {
            mn = min(mn, abs(A[i] - *--it));
        }
    }
    cout << mn << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 