// Created on: 2025-05-24 20:38
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    int A[n + 3];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    int ans = -1;
    sort(A + 1, A + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int need = A[j] - A[i];
            if (need % 2 == 0) {
                ans = max(ans, j - i + 1);
            }
        }
    }

    cout << n - ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 