#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5+9;
pair<int,int>segment[N];
int n,q,m,one[N];

bool ok(int x) {
    int arr[n+1];
    for (int i = 1; i <= n; i++) {
        arr[i] = 0;
    }
    for (int i = 1; i <= x; i++) {
        arr[one[i]] = 1;
    }

    int ps[n+1];
    ps[0] = 0;
    for (int i = 1; i <= n; i++) {
        ps[i] = ps[i-1]+arr[i];
    }


    for (int i = 1; i <= m; i++) {
        int left = segment[i].first, right = segment[i].second;
        if (ps[right]-ps[left-1] > (right-left+1)/2) {
            return true;
        }
    }
    return false;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int l,r; cin >> l >> r;
        segment[i] = make_pair(l,r);
    }

    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> one[i];
    }

    int lo = 1, hi = q, ans = -1;
    while(lo <= hi) {
        int mid = (hi+lo)/2;
        if (ok(mid)) {
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