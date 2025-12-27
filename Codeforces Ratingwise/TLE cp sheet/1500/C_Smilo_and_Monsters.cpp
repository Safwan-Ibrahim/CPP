// Created on: 2025-04-27 05:35
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, A[nn];
ll Pref[nn];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    sort(A + 1, A + n + 1);
    int l = 1, r = n;
    ll ans = 0;
    int have = 0;
    while(l < r) {
        while(l < r && have < A[r]) {
            if (A[l] <= A[r] - have) {
                have += A[l];
                l++;
            }
            else {
                A[l] -= A[r] - have;
                have = A[r];
            }
        }
        if (have == A[r]) {
            r--;
            ans += have + 1;
            have = 0;
        }
        else {
            break;
        }
    }

    if (l == r) {
        if (A[r] == 1) {
            ans += 1;
        }
        else {
            have += (A[r] - have + 1) / 2;
            ans += have + 1;
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