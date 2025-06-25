// Created on: 2025-05-05 20:49
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, k; cin >> n >> k;
    ll sum = 0;
    int A[n + 5];
    int mx = -1, mn = 2e9;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        mx = max(x, mx);
        mn = min(x, mn);
        sum += x;
        A[i] = x;
    }   

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (mx == A[i]) {
            cnt++;
        }
    }
    
    if (sum % 2 == 0 || mx - mn - 1 > k || (cnt > 1 && mx - mn > k)) {
        cout << "Jerry\n";
    }
    else {
        cout << "Tom\n";
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 