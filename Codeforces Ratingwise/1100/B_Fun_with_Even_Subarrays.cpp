// Created on: 2025-01-22 15:45
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int NN = 2e5 + 9;
int N, OP, A[NN];

void solve() {
    cin >> N;
    for (int i = N; i >= 1; i--) {
        cin >> A[i];
    }

    OP = 0;
    for (int i = 1 + 1; i <= N; i++) {
        if (A[i] != A[1]) {
            OP++;
            i += i - 2;
        }
    }

    cout << OP << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T = 1; cin >> T;
    for (int i = 1; i <= T; i++) {
        solve();
    }
    return 0;
} 