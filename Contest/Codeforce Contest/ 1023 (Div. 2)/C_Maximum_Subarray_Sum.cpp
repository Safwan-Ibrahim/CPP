// Created on: 2025-05-05 22:18
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 108;
ll n, k, A[nn];
char S[nn];

ll get_mss(int l, int r) {
    ll max_subarray_sum = -1e12;
    ll sum = -1e12;
    for (int i = l; i <= r; i++) {
        sum = max(A[i], A[i] + sum);
        max_subarray_sum = max(max_subarray_sum, sum);
    }
    return max_subarray_sum;
}

void Try() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    ll mss = get_mss(1, n);
    if (mss == k) {
        cout << "Yes\n";
        for (int i = 1; i <= n; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
        return;
    }

    int ind_zero = -1;
    for (int i = 1; i <= n; i++) {
        if (S[i] == '0') {
            A[i] = -1e12;
            ind_zero = i;
        }
    }

    mss = get_mss(1, n);
    if (mss > k || ind_zero == -1) {
        cout << "No\n"; return;
    }

    ll lo = -1e18, hi = 1e18;
    while(lo <= hi) {
        ll mid = (hi + lo) / 2;
        A[ind_zero] = mid;
        ll got = get_mss(1, n);
        if (got > k) {
            hi = mid - 1;
        }
        else if (got < k) {
            lo = mid + 1;
        }
        else {
            break;
        }
    }

    assert(get_mss(1, n) == k);
    cout << "Yes\n";
    for (int i = 1 ; i <= n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 