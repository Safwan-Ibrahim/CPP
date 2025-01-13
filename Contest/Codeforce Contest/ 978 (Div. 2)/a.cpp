// Created on: 2024-10-14 10:44
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n,r; cin >> n >> r;
    int a[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0, left = 0;
    for (int i = 1; i <= n; i++) {
        ans += (a[i] / 2) * 2;
        left += a[i] % 2;
    }
    int blank = r - (ans / 2);
    ans += min(left,blank);
    ans -= max(0,left - blank);

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