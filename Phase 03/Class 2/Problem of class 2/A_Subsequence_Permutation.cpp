// Created on: 2025-07-10 20:42
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    string A; cin >> A;
    string B = A;
    sort(B.begin(), B.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += A[i] != B[i];
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