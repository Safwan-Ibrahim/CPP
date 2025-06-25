// Created on: 2025-04-18 15:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 105;
int n, k, A[nn];

void Try() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    k *= 2;
    sort(A + 1, A + n + 1);
    map<int, int>Mp;
    for (int i = n - k + 1; i <= n; i++) {
        Mp[A[i]]++;
    }

    int mx_cnt = 0;
    for (auto [x, y] : Mp) {
        mx_cnt = max(mx_cnt, y);
    }

    int rest = k - mx_cnt;
    int ans = 0;
    if (mx_cnt > rest) {
        mx_cnt -= rest;
        ans = mx_cnt / 2;
    }
    for (int i = 1; i <= n - k; i++) {
        ans += A[i];
    }

    cout << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 