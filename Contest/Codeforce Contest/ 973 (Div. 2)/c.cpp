#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n; cin >> n;
    ll a[n+1];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll mn =  1e15, mx = -9;
    while(1) {
        bool entered = false;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i+1]) {
                ll need = (a[i]-a[i+1])/2;
                ll big = a[i]-need;
                ll small = a[i+1]+need;
                a[i] = small;
                a[i+1] = big;
                entered = true;
            }
        }
        if (!entered) {
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        mx = max(mx,a[i]);
        mn = min(mn,a[i]);
    }

    cout << mx - mn << endl;

}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 