#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5+9;
int n,k,a[N];

bool bs(int x) {
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += a[i]/x;
    }
    return cnt >= k;
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    
    for (int i = 1;i <= n; i++) {
        cin >> a[i];
    }

    int lo = 1, hi = 1e5, ans = 0;
    while(lo <= hi) {
        int mid = (hi+lo)/2;
        if (bs(mid)) {
            ans = mid; lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }

    cout << ans << endl;

    
    return 0;
} 