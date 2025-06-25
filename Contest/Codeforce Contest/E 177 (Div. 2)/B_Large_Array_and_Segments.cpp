// Created on: 2025-04-17 20:15
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n, k, need;

bool ok(ll x, vector<ll> &Suf) {
    int i = x % n; 
    if (i == 0) {
        i = n;
    }
    ll sum = Suf[i];
    sum += Suf[1] * ((n * k - x) / n);
    return sum >= need;
}

void Try() {
    cin >> n >> k >> need;
    vector<int>A(n + 2, 0);
    vector<ll>Suf(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    ll sum = 0;
    for (int i = n; i >= 1; i--) {
        sum += A[i];
        Suf[i] = sum;
    }

    ll lo = 1, hi = n * k, ans = 0;
    while(lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (ok(mid, Suf)) {
            ans = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
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