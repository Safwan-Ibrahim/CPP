#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    int a[n+1];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int cnt = 0, mx = -1;
    for (int i = 1; i <= n; i += 2) {
        mx = max(mx,a[i]);
        cnt++;
    }

    int ans1 = mx+cnt; mx = -1; cnt = 0;
    for (int i = 2; i <= n; i += 2) {
        mx = max(mx,a[i]);
        cnt++;
    }

    int ans2 = mx+cnt;
    cout << max(ans1,ans2) << endl;
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 