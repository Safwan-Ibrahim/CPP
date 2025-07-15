// Created on: 2025-07-06 20:51
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
ll n, A[nn];

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    ll mn = 1e18;
    ll sum = 0;
    vector<ll>Pref(n + 3, 0), Mn(n + 3, 0);
    Mn[0] = mn;
    for (int i = 1; i <= n; i++) {
        mn = min(mn, A[i]);
        Mn[i] = mn;
        sum += mn;
        Pref[i] = sum;
    }
    
    ll ans = Pref[n];
    for (int i = 2; i <= n; i++) {
        ans = min(ans, Pref[i - 2] + min(Mn[i - 2], A[i - 1] + A[i]));
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