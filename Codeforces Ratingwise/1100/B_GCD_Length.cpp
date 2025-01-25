// Created on: 2025-01-22 13:42
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int digit(int N) {
    int ans = 1;
    while(N > 9) {
        N /= 10;
        ans++;
    }
    return ans;
}

void solve() {
    int A, B, C; cin >> A >> B >> C;

    int G = pow(10, C - 1);
    int X = G, Y = G;
    while(digit(X) < A) {
        X *= 2;
    }
    while(digit(Y) < B) {
        Y *= 3;
    }

    cout << X << " " << Y << endl;    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T = 1; cin >> T;
    for (int i = 1; i <= T; i++) {
        solve();
    }
    return 0;
} 