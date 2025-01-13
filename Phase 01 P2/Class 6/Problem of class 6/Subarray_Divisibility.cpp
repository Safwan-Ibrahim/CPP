#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int a[n+1];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ps[n+1]; ps[0] = 0;

    for (int i = 1; i <= n; i++) {
        ps[i] = ((ps[i-1]%n + a[i]%n)+n)%n;
    }

    map<int,int>mp; ll ans = 0;
    mp[0]++;
    for (int i = 1; i <= n; i++) {
        ans += mp[ps[i]];
        mp[ps[i]]++;
    }

    cout << ans << endl;

    return 0;
} 