#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5+9;
int n,arr[N];

ll pairs(int l, int r) 
{
    if (l >= r) {
        return 0;
    }

    ll cnt = 0;
    int mid = l+(r-l)/2;
    cnt += pairs(l,mid);
    cnt += pairs(mid+1,r);

    vector<int>v;
    for (int i = mid+1; i <= r; i++) {
        v.push_back(arr[i]);
    }

    sort(v.begin(),v.end());
    for (int i = l; i <= mid; i++) {
        cnt += lower_bound(v.begin(),v.end(),arr[i])-v.begin();
    }

    return cnt;
}

void solve()
{   
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    cout << pairs(1,n) << endl;
}

int32_t main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 