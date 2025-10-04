// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, m, A[nn], B[nn];

void Try() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        cin >> A[i] >> B[i];
    }
    
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int dif = A[i] - A[i - 1];
        if (B[i - 1] == B[i]) {
            if (dif & 1) ans += dif - 1;
            else ans += dif;
        }
        else {
            if (dif & 1) ans += dif;
            else ans += dif - 1;
        }
    }
    
    ans += m - A[n];

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