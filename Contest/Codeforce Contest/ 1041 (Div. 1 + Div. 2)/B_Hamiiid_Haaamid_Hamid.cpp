// Created on: 2025-08-07 20:58
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, pos; cin >> n >> pos;

    char S[n + 5];
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }

    l = 0, r = n + 1;
    for (int i = pos; i >= 1; i--) {
        if (S[i] == '#') {
            l = i; break;
        }
    }

    for (int i = pos; i <= n; i++) {
        if (S[i] == '#') {
            r = i; break;
        }
    }

    int a, b;
    a = min(l, n + 1 - (pos + 1));
    b = min(n + 1 - r, pos - 1);
    int ans = max(a, b);
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