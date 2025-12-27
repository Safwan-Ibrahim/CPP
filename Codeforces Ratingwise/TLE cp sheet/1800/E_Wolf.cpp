// Created on: 2025-11-26 17:48
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, A[nn], O[nn], q;

void Try() {
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        O[A[i]] = i;
    }
    
    for (int i = 1; i <= q; i++) {
        int l, r, k; cin >> l >> r >> k;
        int id = O[k];

        if (l > r || l > id || r < id) {
            cout << -1 << " "; continue;
        }
        int mnc = 0, mxc = 0, mno = 0, mxo = 0;
        int big = n - k;
        int small = k - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (id == mid) {
                break;
            }
            if (id < mid) {
                mxc++;
                if (A[mid] < k) mxo++;
                r = mid - 1;
            }
            else {
                mnc++;
                if (A[mid] > k) mno++;
                l = mid + 1;
            }
        }

        if (mnc > small || mxc > big) cout << -1 << " ";
        else cout << max(mxo, mno) * 2 << " ";
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