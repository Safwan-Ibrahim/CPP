// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 105;
int n, y, A[nn], Cnt[nn], Ps[nn];

void Try() {
    cin >> n >> y;
    
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, A[i]);
        Cnt[A[i]]++;
    }
    
    int ps = 0;
    for (int i = 1; i <= mx; i++) {
        ps += Cnt[i];
        Ps[i] = ps;
    }
    
    ll ans = (mx == 1 ? n : -1e18);
    for (int x = 2; x <= mx; x++) {
        int tt = 0;
        ll sum = 0;
        for (int i = 1; i <= (mx + x - 1) / x; i++) {
            int cnt = Ps[min(x * i, mx)] - Ps[min(mx, x * i - x)];
            sum += cnt * 1LL * i;
            tt += min(Cnt[i], cnt);
        }
        ans = max(ans, sum - 1LL * (n - tt) * y);
    }
    
    cout << ans << endl;
    
    for (int i = 1; i <= n; i++) {
        Cnt[A[i]]--;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 