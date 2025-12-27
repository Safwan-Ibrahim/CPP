// Created on: 2025-11-20 21:37
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    int A[n + 1], B[n + 1];

    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        a ^= A[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> B[i];
        b ^= B[i];
    }

    int msb = -1;
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < 25; k++) {
            int ba = (A[i] >> k) & 1;
            int bb = (B[i] >> k) & 1;
            int bxa = (a >> k) & 1;
            int bxb = (b >> k) & 1;
            if (bxb != bxa && ba != bb) {
                msb = max(msb, k);
            }
        }
    }

    if (msb != -1) {
        for (int i = n; i >= 1; i--) {
            int ba = (A[i] >> msb) & 1;
            int bb = (B[i] >> msb) & 1;
            int bxa = (a >> msb) & 1;
            int bxb = (b >> msb) & 1;
            if (bxb != bxa && ba != bb) {
                if (i & 1) {
                    cout << "Ajisai\n";
                }
                else cout << "Mai\n";
                return;
            }
        }
    }

    if (a == b) {
        cout << "Tie\n";
    }
    else if (a > b) {
        cout << "Ajisai\n";
    }
    else cout << "Mai\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 