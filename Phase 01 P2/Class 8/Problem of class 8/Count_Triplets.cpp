#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k; cin >> n >> k;
    int a[n + 1];
    map<ll,int>l,r;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        r[a[i]]++;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int m = a[i];
        r[m]--;
        if (m % k != 0) {
            l[m]++;
            continue;
        }
        int f = m / k;
        ll t = 1LL * m * k;
        ans += 1LL * l[f] * r[t];
        l[m]++;
    }

    cout << ans << endl;
    return 0;
} 