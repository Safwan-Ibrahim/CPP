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
    ll prev_ans = k;
    ll ans = k+rt(k);

    while(rt(ans) > rt(prev_ans)) {
        prev_ans = ans;
        ans = k+(rt(ans));
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