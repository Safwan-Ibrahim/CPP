// Created on: 2025-01-13 10:33
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const ll L = 1e15, N = 1e5 + 9;
int n, a[N];

ll op(int num) {
    ll p = 1;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += abs(a[i] - p);
        if (num >= 1e15 / p) {
            return L;
        }
        if (ans > L) {
            return L;
        }
        p *= num;
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    ll mn = L;
    for (int i = 1; i <= 1e5 + 9; i++) {
        mn = min(mn, op(i));
    }

    cout << mn << endl;
    return 0;
}