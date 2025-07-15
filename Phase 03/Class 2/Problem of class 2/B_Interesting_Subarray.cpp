// Created on: 2025-07-12 02:47
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    int mn = A[1] - 1, id = 1;
    int mx = A[1] + 1, id2 = 1;
    for (int i = 2; i <= n; i++) {
        if (A[i] - i - 1 - mn >= 0) {
            cout << "YES\n";
            cout << id << " " << i << endl; return;
        }
        if (mx - 1 - (A[i] + i) >= 0) {
            cout << "YES\n";
            cout << id2 << " " << i << endl; return;
        }
        if (A[i] - i < mn) {
            mn = A[i] - i;
            id = i;
        }
        if (A[i] + i > mx) {
            mx = A[i] + i;
            id2 = i;
        }
    }

    cout << "NO\n";
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 