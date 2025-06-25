// Created on: 2025-05-04 03:58
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, k, A[nn];

void Try() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    int l = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i == n || A[i] >= A[i + 1] * 2) {
            int back = i - k;
            ans += max(0, back - l + 1);
            l = i + 1;
        }
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