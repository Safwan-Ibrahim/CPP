// Created on: 2024-10-24 22:17
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    ll a[n + 1]; a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }

    int l = 0;
    multiset<ll>st;
    st.insert(0);
    ll ans = 0;
    for (int r = 1; r <= n; r++) {
        if (st.find(a[r]) != st.end()) {
            while(l != r) {
                st.erase(st.find(a[l]));
                l++;
            }
            ans++;
        }
        st.insert(a[r]);
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