// Created on: 2024-10-20 15:45
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 7;
int n,k,a[N];

bool ok(int x) {
    ll taken = 0;
    for (int i = 1; i < x; i++) {
        taken += a[i];
    }
    ll left = k - taken;
    int right = n - x + 1;
    return (left + right - 1) / right <= a[x];
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    int last_index;
    int lo = 1, hi = n;
    while(lo <= hi) {
        int mid = (hi + lo) / 2;
        if(ok(mid)) {
            last_index = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    ll ans = 0;
    ll taken = 0;
    for (int i = 1; i < last_index; i++) {
        ans += a[i] + 1;
        taken += a[i];
    }

    cout << ans + k - taken << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 