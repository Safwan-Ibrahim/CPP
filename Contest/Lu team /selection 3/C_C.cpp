// Created on: 2025-04-24 13:08
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
ll n, k, A[nn];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    map<ll, ll>Mp1, Mp2;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++) {
        if (A[i] % k == 0) {
            Mp2[A[i]] += Mp1[A[i] / k];
        }
        Mp1[A[i]]++;
    }


    // for (auto [x, y] : Mp2) {
    //     cerr << x << " " << y << endl;
    // }
    
    for (int i = 1; i <= n; i++) {
        Mp1[A[i]]--;
        Mp2[1LL * k * A[i]] -= Mp1[A[i] * k];
        __int128 num = (__int128) A[i] * k * k;
        if (num <= 1e18 && num >= -1e18) {
            ans += Mp2[A[i] * k * k];
        }
    }

    cout << ans << endl;
    
    return 0;
} 