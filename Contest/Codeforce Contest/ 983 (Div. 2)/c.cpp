// Created on: 2024-11-03 18:57
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    int l = 1;
    int ans = n - 2;
    for (int r = 3; r <= n; r++) {
        while(r - l > 1 && a[l] + a[l + 1] <= a[r]) {
            l++;
        }
        ans = min(ans, n - r + (l - 1));
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