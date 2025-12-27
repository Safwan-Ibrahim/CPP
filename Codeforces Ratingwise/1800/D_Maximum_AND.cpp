// Created on: 2025-12-08 15:51
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int n, A[nn], B[nn];

void off_bit(int& x, int k) {
    x &= ~(1 << k);
}

void set_bit(int& x, int k) {
    x |= 1 << k;
}

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }

    int ans = 0;
    for (int k = 29; k >= 0; k--) {

        set_bit(ans, k);
        vector<int> C, D;
        for (int i = 1; i <= n; i++) {
            C.push_back(A[i] & ans);
            D.push_back(~B[i] & ans);
        }

        sort(C.begin(), C.end());
        sort(D.begin(), D.end());

        if (C != D) {
            off_bit(ans, k);
        }
    }

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