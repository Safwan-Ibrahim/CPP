// Created on: 2025-06-03 20:39
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    vector<int> A(3, 0);
    int ans = 0;
    while(*min_element(A.begin(), A.end()) != n) {
        sort(A.begin(), A.end());
        A[0] += min(n - A[0], A[1] * 2 + 1 - A[0]);
        ans++;
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