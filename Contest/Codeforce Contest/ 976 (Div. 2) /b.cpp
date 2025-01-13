#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll rt (ll x) {
    ll r = sqrtl(x);
    while(r*r <= x) r++;
    while(r*r > x) r--;
    return r;
}

void solve()
{
    ll k; cin >> k;
    ll lo = 1, hi = 2e18, ans;
    while(lo <= hi) {
        ll mid = lo +(hi-lo)/2;
        if (mid-rt(mid) >= k) {
            ans = mid;
            hi = mid-1;
        }
        else {
            lo = mid+1;
        }
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