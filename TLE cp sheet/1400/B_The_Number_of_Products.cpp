// Created on: 2025-05-05 01:22
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, A[nn];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x >= 0) {
            A[i] = 0;
        }
        else {
            A[i] = 1;
        }
    }

    int neg = 0, x = 0;
    for (int i = 1; i <= n; i++) {
        x ^= A[i];
        if (x) {
            neg++;
        }
    }

    int pos = n - neg;
    ll ans_neg = 0;
    int xor_till_now = 0;
    for (int i = 1; i <= n; i++) {
        if (xor_till_now == 1) {
            ans_neg += pos;
        }
        else {
            ans_neg += neg;
        }
        xor_till_now ^= A[i];
        if (xor_till_now == 1) {
            neg--;
        }
        else {
            pos--;
        }
    }

    ll ans_pos = 1LL * n * (n + 1) / 2 - ans_neg;
    cout << ans_neg << " " << ans_pos << endl;
    return 0;
} 