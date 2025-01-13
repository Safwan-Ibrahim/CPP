#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n;

bool ok(ll x) {
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += min(n,x/i);
    }
    return cnt >= n*n/2+1;
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    ll lo = 1, hi = n*n, ans = 0;
    while(lo <= hi) {
        ll mid = (hi+lo)/2;
        if (ok(mid)) {
            ans = mid;
            hi = mid-1;
        }
        else {
            lo = mid+1;
        }
    }

    cout << ans << endl;

    return 0;
} 