// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, k, A[nn];

void Try() {
    cin >> n >> k;
    
    vector<int> Cnt(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        Cnt[A[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        if (Cnt[i] % k != 0) {
            cout << 0 << endl; return;
        }
        Cnt[i] /= k;
    }

    vector<int> Cur(n + 1, 0);

    ll ans = 0;
    int r = 1;
    for (int l = 1; l <= n; l++) {
        while (r <= n && Cur[A[r]] < Cnt[A[r]]) {
            Cur[A[r]]++;
            r++;
        }
        ans += r - l;
        Cur[A[l]]--;
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