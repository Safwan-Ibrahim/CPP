// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn];

void Try() {
    cin >> n;

    int c = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        c += A[i] == 0;
        sum += A[i];
    }
    
    if (c == 1) {
        int v = 1LL * n * (n + 1) / 2 - sum;
        for (int i = 1; i <= n; i++) {
            if (A[i] == 0) A[i] = v;
        }
    }

    int l = 0, r = 0;
    if (c <= 1) {
        for (int i = 1; i <= n; i++) {
            if (A[i] != i && !l) l = i;
            if (A[i] != i) r = i;
        }
        if (!l) {
            cout << 0 << endl;
        }
        else cout << r - l + 1 << endl;
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        if ((A[i] != i || A[i] == 0) && !l) l = i;
        if (A[i] != i || A[i] == 0) r = i;
    }
    if (!l) {
        cout << 0 << endl; return;
    }
    cout << r - l + 1 << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 