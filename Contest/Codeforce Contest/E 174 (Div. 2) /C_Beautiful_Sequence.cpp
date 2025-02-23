// Created on: 2025-02-18 22:29
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int M = 998244353;

void Try() {
    int n; cin >> n;
    int A[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    int ans = 0, cut = 0, sum = 0, cnt3 = 0;
    for (int i = n; i >= 1; i--) {
        if (A[i] == 3) {
            cnt3++;
            sum = (sum + 1) % M;
        }
        else if (A[i] == 2) {
            sum = 1LL * sum * 2 % M;
        }
        else {
            ans = (1LL * ans + sum) % M;
            cut = (1LL * cut + cnt3) % M;
        }
    }

    cout << (ans - cut + M) % M << endl;
     
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 