// Created on: 2025-02-25 21:43
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    int A[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    int mx = 0, ans_l = 1, ans_r = 1;
    for (int l = 1; l <= n; l++) {
        int big = 0, small = 0;
        for (int r = l + 1; r <= n; r++) {
            if (A[r] > A[l]) {
                big++;
            }
            else if (A[r] < A[l]) {
                small++;
            }
            if (small - big > mx) {
                mx = small - big;
                ans_l = l;
                ans_r = r;
            }
        }
    }

    cout << ans_l << " " << ans_r << endl;
    
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 