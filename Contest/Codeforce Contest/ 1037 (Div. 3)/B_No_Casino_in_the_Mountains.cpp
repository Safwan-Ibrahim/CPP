// Created on: 2025-07-17 20:39
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, k; cin >> n >> k;
    int A[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    int ans = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] == 0) {
            cnt++;
            if (cnt == k) {
                ans++;
                cnt = 0;
                if (i + 1 <= n) {
                    A[i + 1] = 1;
                }
            }
        }
        else {
            cnt = 0;
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