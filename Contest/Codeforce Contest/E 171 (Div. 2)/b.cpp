// Created on: 2024-10-28 20:26
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    ll a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 1 << endl; return;
    }

    ll ans = -1;
    if (n % 2 == 0) {
        for (int i = 2; i <= n; i += 2) {
            ans = max(ans, a[i] - a[i - 1]);
        }
        cout << ans << endl; return;
    }
    ans = 1e18 + 9;
    set<ll>st;
    for (int i = 1; i <= n; i++) {
        st.insert(a[i]);
    }

    for (int i = 1; i <= n; i++) {
        ll need = a[i];
        if (st.find(need + 1) == st.end() || st.find(need - 1) == st.end()) {
            st.erase(need);
        }
        else {
            continue;
        }
        ll ans2 = -1;
        int v = 0;
        ll agor = 0;
        for (auto x : st) {
            v %= 2;
            if (v == 0) {
                agor = x;
                v++;
                continue;
            }
            ans2 = max(x - agor, ans2);
            v++;
        }
        st.insert(need);
        ans = min(ans,ans2);
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