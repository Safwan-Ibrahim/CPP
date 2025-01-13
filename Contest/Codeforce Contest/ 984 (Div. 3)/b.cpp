// Created on: 2024-11-02 20:54
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n,k; cin >> n >> k;
    ll a[k + 5];
    memset(a,0,sizeof(a));

    for (int i = 1; i <= k; i++) {
        int x,y; cin >> x >> y;
        a[x] += y;
    }
    
    sort(a + 1, a + k + 1, greater<>());
    ll ans = 0;
    for (int i = 1; i <= min(n,k); i++) {
        ans += a[i];
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 