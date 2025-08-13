// Created on: 2025-08-10 21:16
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn], B[nn];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }
    
    for (int i = 1; i + 1 <= n; i++) {
        if ((A[i] ^ B[i]) != A[i + 1] && (A[i] ^ B[i]) != B[i + 1] && A[i] != B[i]) {
            cout << "NO\n"; return;
        }
    }

    cout << (A[n] == B[n] ? "YES\n" : "NO\n");
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 