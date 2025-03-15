// Created on: 2025-02-28 21:52
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 8;
int last_x, n, A[N]; 
ll k; 

int value(ll x) {
    if (x <= n) {
        return A[x];
    }
    ll m = x / 2;
    if (m <= n) {
        int tmp = 0;
        for (int i = 1; i <= m; i++) {
            tmp ^= A[i];
        }
        return tmp;
    }
    if (m & 1) {
        return last_x;
    }
    return last_x ^ value(m);
}

void Try() {
    cin >> n >> k >> k;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    if (n % 2 == 0) {
        int x = 0;
        for (int i = 1; i <= n / 2; i++) {
            x ^= A[i];
        }
        n++;
        A[n] = x; 
    }

    last_x = 0;
    for (int i = 1; i <= n; i++) {
        last_x ^= A[i];
    }

    cout << value(k) << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 