// Created on: 2025-06-14 06:34
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int pn, k, A[nn], B[nn];
ll pref[nn];

void Try() {
    cin >> pn >> k;
    for (int i = 1; i <= pn; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= pn; i++) {
        cin >> B[i];
    }

    ll mx = 0;
    sort(A + 1, A + pn + 1);
    sort(B + 1, B + pn + 1);
    
    for (int i = 1; i <= pn; i++) {
        int a = A[i];
        int b_not_smaller_than_a = B + pn + 1 - lower_bound(B + 1, B + pn + 1, a);
        int a_not_smaller_than_a = A + pn + 1 - lower_bound(A + 1, A + pn + 1, a);
        int neg = b_not_smaller_than_a - a_not_smaller_than_a;
        if (neg <= k) {
            ll tt = 1LL * a * pn;
            int b_smaller_than_a = lower_bound(B + 1, B + pn + 1, a) - (B + 1);
            mx = max(mx, tt - (1LL * b_smaller_than_a * a));
        }
        a = B[i];
        b_not_smaller_than_a = B + pn + 1 - lower_bound(B + 1, B + pn + 1, a);
        a_not_smaller_than_a = A + pn + 1 - lower_bound(A + 1, A + pn + 1, a);
        neg = b_not_smaller_than_a - a_not_smaller_than_a;
        if (neg <= k) {
            ll tt = 1LL * a * pn;
            int b_smaller_than_a = lower_bound(B + 1, B + pn + 1, a) - (B + 1);
            mx = max(mx, tt - (1LL * b_smaller_than_a * a));
        }
    }

    cout << mx << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 