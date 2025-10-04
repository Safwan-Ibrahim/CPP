// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 4e5 + 17;
int n, k, A[nn]; 
ll Ps[nn], On[nn], En[nn];

void Try() {
    cin >> n;
    k = n, n <<= 1;
    
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    ll on = 0, en = 0, ps = 0;
    for (int i = 1; i <= n; i++) {
        if (i & 1) on -= A[i], en += A[i];
        else on += A[i], en -= A[i];
        ps += A[i];
        Ps[i] = ps, On[i] = on, En[i] = en;
    }

    for (int i = 0; i < k; i++) {
        ll ans = Ps[n] - Ps[n - i] - Ps[i];
        if (i & 1) ans += En[n - i] - En[i];
        else ans += On[n - i] - On[i];
        cout << ans << " ";
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