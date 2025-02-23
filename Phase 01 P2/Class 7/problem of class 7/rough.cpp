#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; ll k; cin >> n >> k;
    ll a[n+1];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int r = 1; ll ans = 0;

    multiset<ll>ms;

    for (int l = 1; l <= n; l++) {
        if (ms.empty()) {
            ms.insert(a[r++]);
        }
        while(max(*(ms.rbegin()),a[r])-min(*(ms.begin()),a[r]) <= k && r <= n) {
            ms.insert(a[r++]);
        }
        ans += r-l;
        ms.erase(ms.find(a[l]));
    }

    cout << ans << endl;
    
    return 0;
} 