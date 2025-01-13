#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n,d,k; cin >> n >> d >> k;
    int start[k+1],end[k+1];

    for (int i = 1; i <= k; i++) {
        cin >> start[i];
        cin >> end[i];
    }

    sort(start+1,start+k+1);

    int last = -1;
    int most = -1;
    for (int i = 1; i <= k; i++) {
        int need = start[i]-(d-1);
        auto it = lower_bound(start+1,start+k+1,need);
        if (&start[i]-it > most) {
            most = &start[i]-it;
            last = start[i];
        }
    }

    cout << max(1,last-(d-1)) << endl;
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 